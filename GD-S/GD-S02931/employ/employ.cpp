#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+10,mod=998244353;
int n,m,c[N],ans,a[N],sl[N];
int fac[N];
bool s[N],v[N];
void dfs(int x){
	if(x==n+1){
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(s[i]==0||cnt>=c[a[i]])cnt++;
			else sum++;
		}
		if(sum>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++)if(v[i]==0){
		v[i]=1;a[x]=i;
		dfs(x+1);
		v[i]=0;a[x]=0;
	}
}
void dfs2(int x){
	
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=(fac[i-1]*i)%mod;
	string x;cin>>x;
	bool flag=1;
	int sum=0;sl[1]=0;
	for(int i=0;i<x.size();i++)s[i+1]=x[i]-'0',flag=(flag&&s[i+1]),sum+=s[i+1];
	for(int i=2;i<=n;i++)sl[i]+=(!s[i-1]);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	sort(c+1,c+n+1);
	int zz=1,cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]){
			while(c[zz]<=sl[i]&&zz<=n)zz++;
			if(zz!=n+1)cnt++;
		}
	}
	if(cnt!=m){
		printf("0\n");
		return 0;
	}
	if(sum<m){
		printf("0\n");
		return 0;
	}
	if(n<=10){
		memset(v,0,sizeof(v));ans=0;
		dfs(1);
		printf("%lld\n",ans);
		return 0;
	}
	if(flag){
		printf("%lld\n",fac[n]);
		return 0;
	}
	if(!flag&&m==n){
		printf("0\n");
		return 0;
	}
	if(m==1){
		if(s[1]==1){
			printf("%lld\n",fac[n]);
			return 0;
		}
		
	}
	return 0;
}
