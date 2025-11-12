//polygon
#include<bits/stdc++.h>
using namespace std;
long long n,a[10010],flag=0,k[10010];
unsigned long long ans=0;
void dfs(long long x,long long now,long long z,long long s){
	if(now==1){
		if(s>=1&&z+a[now]>a[x]) ans++;
		if(s>=2&&z>a[x]) ans++;
		return ;
	}
	dfs(x,now-1,z+a[now],s+1);
	dfs(x,now-1,z,s);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	if(flag==0){
		unsigned long long p=1,q=1;
		for(int i=n;i>=n-2+1;i--){
			p=p*i;
			p=p%998244353;
		}
	    q=2;
		for(int t=3;t<=n;t++){
			p=p*(n-t+1);
			p=p%998244353;
			q=q*t;
			q=q%998244353;
			ans+=(p/q);
			ans=ans%998244353;
		}
	}
	else{
		sort(a+1,a+n+1);
	    if(n<=3){
	    	if((a[1]+a[2])>a[3]) cout<<1;
	    	else cout<<0;
	    	return 0;
		} 
		for(int i=3;i<=n;i++){
		    dfs(i,i-1,0,0);
		}
	}
	cout<<ans;
	return 0;
}
