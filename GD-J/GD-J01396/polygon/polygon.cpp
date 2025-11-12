#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;

int n,a[5010],maxn,cnt,f,ans,b[5010];

int is(int x,int y){
	long long ans=1,a=x,b=1;
	while(y){
		if(y&b) ans=ans*a%mod,y-=b;
		b<<=1;
		a=a*a%mod;
	}
	return ans;
}

void dfs(int x){
	if(x>n){
		cnt=f=0;
		for(int i = 1;i <= n;i++) if(b[i]) cnt+=a[i],f=i;
		if(cnt>2*a[f]) ans=(ans+1)%mod;
		return;
	}dfs(x+1);
	b[x]=1;
	dfs(x+1);
	b[x]=0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i],maxn=max(maxn,a[i]);
	if(!maxn) return cout<<"0\n",0;
	if(maxn==1){
		long long ans=0,cnt=0;
		for(int i = 1;i <= n;i++) if(a[i]) cnt++;
		if(cnt<3) return cout<<"0\n",0;
		ans=1ll*((is(2,cnt)-1-cnt-cnt*(cnt-1)/2)%mod*is(2,n-cnt)%mod+mod)%mod;
		cout<<ans<<'\n';
		return 0;
	}sort(a+1,a+n+1);
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
