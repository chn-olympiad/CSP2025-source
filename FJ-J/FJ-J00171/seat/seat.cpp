#include<bits/stdc++.h>
using namespace std;

int n,m,a[105],s[15][15];
bool t[105];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) t[a[i]]=true;
	}
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
		if(t[a[i]]){
			int j=n*m-i+1;
			int p=ceil(j*1.0/n);
			cout<<p<<" ";
			if(p%2==0)
				if(j%n==0) cout<<1;
				else cout<<n-j%n+1;
			else 
				if(j%n==0) cout<<n;
				else cout<<j%n;
			break;
		}
	return 0;
	
}
