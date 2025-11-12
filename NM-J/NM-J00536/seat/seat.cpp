#include<bits/stdc++.h>
using namespace std;
int n,m;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int qwe[m][n];
	vector<int>a;
	int ren=0;
	for(int i=0;i<n*m;i++){
		int q;
		cin>>q;
		if(i==0)ren=q;
		a.push_back(q);
	}
	sort(a.begin(),a.end());
	int c=0,r=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
		for(int j=0;j<n;j++){
			qwe[i-1][j]=a.back();
			a.pop_back();
			
		}
		}
	else{
	for(int j=n-1;j>=0;j--){
			qwe[i-1][j]=a.back();
			a.pop_back();
		}
		}
		
	}
	for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	if(qwe[j][i]==ren){
	c=j+1;
	r=i+1;
	}
	}
	}
	cout<<c<<" "<<r;
	
	return 0;
	}
