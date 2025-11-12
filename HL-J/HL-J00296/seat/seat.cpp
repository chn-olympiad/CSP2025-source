#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p;
	vector<int>a(n*m+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
			cin>>a[(i-1)*m+j];
			if(i==1&&j==1){
				p=a[(i-1)*m+j];
			}
		}
	}
	
	sort(a.begin()+1,a.end(),cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			p=i;
			break;
		}
	}
	cout<<(p-1)/n+1<<" ";
	if(((p-1)/n+1)%2==1){
		if(p%n==0){
			cout<<n;
		}
		else{
			cout<<p%n;
		}
		
	}
	else{
		
		if(n-p%n+1==n+1){
			cout<<1;
		}
		else{
			cout<<n-p%n+1;
		}
	}
	return 0;
}
