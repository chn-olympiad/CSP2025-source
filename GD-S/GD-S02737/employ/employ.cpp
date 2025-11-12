#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=503,mod=998244353;
ll ji[N]; 
int n,m,c[N],p[N],dp[2][20][1<<20],ans;
void Add(int &x,int y){((x+=y)>=mod)&&(x-=mod);}
char s[N];
ll calc(){
	ll ans=1;int cnt=0;
	for(int i=1;i<=n;i++) if(s[i]=='1'){
		int sum=0;
		for(int j=1;j<=n;j++) if(c[j]<=i-1) sum++;
		if(sum<=cnt) return 0;
		ans=ans*(sum-cnt)%mod,cnt++;
	}
	return ans*ji[n-cnt]%mod;
}
bool checkA(){for(int i=1;i<=n;i++) if(s[i]=='0') return 0;return 1;}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1),ji[0]=1;
	for(int i=1;i<=n;i++) scanf("%d",c+i),p[i]=i,ji[i]=ji[i-1]*i%mod;
	sort(c+1,c+1+n);
	if(n<=10){
		do{
			int cnt=0;
			for(int i=1;i<=n;i++) if(s[i]=='0' || cnt>=c[p[i]]) cnt++;
			ans+=(cnt<=n-m);
		}while(next_permutation(p+1,p+1+n));
		printf("%d\n",ans);
	}else if(n<=18){
		dp[0][0][0]=1;//前i个cnt=j用了S中的数 
		for(int i=1;i<=n;i++){
			int now=i&1,pre=now^1;
			memset(dp[now],0,sizeof(dp[now]));
			for(int j=0;j<=min(i,m);j++) for(int S=0;S<(1<<n);S++) if(dp[pre][j][S]){
				for(int k=1;k<=n;k++) if(!((S>>k-1)&1)) Add(dp[now][j+(s[i]=='0' || j>=c[k])][S|(1<<k-1)],dp[pre][j][S]);
			}
		}
		for(int j=0;j<=n-m;j++) Add(ans,dp[n&1][j][(1<<n)-1]);
		printf("%d\n",ans);
	}else if(m==n){
		for(int i=1;i<=n;i++)
			if(s[i]=='0' || !c[i]) return puts("0"),0;
		printf("%lld\n",ji[n]);
	}else if(m==1) printf("%lld\n",(ji[n]-calc()+mod)%mod);
	else puts("0");
	return 0;
}
/*
18 10
110101101110110101
0 0 0 0 0 0 0 5 9 3 12 13 4 9 3 1 15 6
17:0?
*/
