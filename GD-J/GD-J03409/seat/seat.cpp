#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n*m,0);
	vector<vector<int>> k(n,vector<int>(m,0));
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r=a[0];
	sort(a.begin(),a.end());
	int x=a.size()-1;
	for(int j=0;j<m;j++){
		if(j%2==0){
			for(int i=0;i<n;i++){
				k[i][j]=a[x];
				x--;
			}
		}else{
			for(int i=n-1;i>=0;i--){
				k[i][j]=a[x];
				x--;
			}
		}
	}
	int p=0,q=0,f=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(k[i][j]==r){
				p=i+1,q=j+1,f=1;
			}
		}
		if(f==1) break;
	}
	cout<<q<<' '<<p;
	return 0;
} 
