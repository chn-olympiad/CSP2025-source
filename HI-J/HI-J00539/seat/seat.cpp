#include<bits/stdc++.h>
using namespace std;
#define ll long long
int b[1000];
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int h=b[1];
	for(int i=1;i<=n*m;i++){
		for(int k=1;k<=m*n-1;k++)
		{
			if(b[k]<b[k+1]) swap(b[k],b[k+1]);
		}
	}
	for(int u=1;u<=n*m;u++){
		if(b[u]==h){
			f=u;
		}
	}
	int o=0,p=0;
	if(f<n||f==n){
		o=1;
	}
	if(f>n){
		o=f/n;
		if(f%n!=0) o++;
	}
	if(o%2!=0){
		cout<<o<<" "<<f-(o-1)*n;
	}
	if(o%2==0){
		cout<<o<<" ";
		
			int s=f-n*(o-1);
			cout<<n+1-s;
		
	}
	return 0;
}


