#include <bits/stdc++.h>
using namespace std;
int a[5005],s[5005];
int MOD=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int mx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+a[i];	
	}
	int cnt=0;
	if(mx==1){
		int m=n-2;
		cnt=((m+1)*m)%MOD/2;
	}
	
	cout<<cnt%MOD<<endl; 
	return 0;
}
