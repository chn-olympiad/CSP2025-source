#include<bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
int n,m,a[505],d[505],p[505],r[505],l[505],fac[505],x,cnt,ans;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s,s=" "+s,fac[0]=1;
	for(int i=1;i<=n;i++)cin>>a[i],fac[i]=fac[i-1]*i%mod;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='1')d[++x]=cnt;
		else cnt++;
	}
	if(n<=18){
		for(int i=1;i<=n;i++)p[i]=i;
		do{
			int cnt=0;
			for(int i=1;i<=x;i++)if(cnt+d[i]>=a[p[i]])cnt++;
			ans+=x-cnt>=m;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<"\n",exit(0);
	}
	if(m==1){
		for(int i=1;i<=x;i++)r[i]=d[i]+i-1;
		ans=1;
		for(int i=1;i<=x;i++){
			int o=upper_bound(a+1,a+n+1,r[i])-a-1;
			if(o<=i-1){ans=0;break;}ans=ans*(o-(i-1))%mod;
		}
		ans=ans*fac[n-x]%mod;
		cout<<(fac[n]-ans+mod)%mod,exit(0);
	}
	if(m==n){
		for(int i=1;i<=x;i++)l[i]=d[i]+1;
		reverse(l+1,l+x+1);
		ans=1;
		for(int i=1;i<=x;i++){
			int o=lower_bound(a+1,a+n+1,l[i])-a;
			if(x-o+1<=i-1){ans=0;break;}ans=ans*(x-o+1-(i-1))%mod;
		}
		cout<<ans<<"\n",exit(0);
	}
	cout<<0;
}
