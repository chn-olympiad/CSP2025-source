#include<bits/stdc++.h>
using namespace std;
const int N=555,mod=998244353;
int n,m,s[N],a[N],cnt=0;
long long zhs(int n,int m){
	long long jca=1,jcb=1;
	for(int i=max(m,n-m)+1;i<=n;i++){
		jca*=i;
		jca%=mod;
	}
	for(int i=1;i<=min(m,n-m);i++){
		jcb*=i;
	    jcb%=mod;
	}
	return jca/jcb;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	string ss;
	cin>>ss;
	for(int i=0;i<ss.size();i++){
		cnt++;
		s[cnt]=int(ss[i]-'0');
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	bool bf=1;
	for(int i=1;i<=cnt;i++){
		if(s[i]!=1){
			bf=0;
			break;
		}
	}
	if(m==n){
		if(bf==1) cout<<1;
		else cout<<0;
	}
	else if(bf==1 or m==1){
		long long ans1=1,ans2=1,ans=1,sum=n;
		cnt=0;
		ans=max(1ll*1,zhs(n,m));
		for(int i=1;i<=m;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
	else cout<<m*n;
	return 0;
}
