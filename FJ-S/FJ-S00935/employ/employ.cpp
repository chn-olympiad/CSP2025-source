#include<bits/stdc++.h>
using namespace std;

const long long mod=998244353;
int n,m,c[505],s[505],sm[505],p[505],t[505],la,su;
long long fac[505];

int dfs(int k){
	if(k==n+1) {
		int sum=0;for(int i=1;i<=n;i++) if(s[i]==1&&c[p[i]]>sm[i]) sum++;
		if(sum>=m) return 1;else return 0;
	}
	int sum=0;
	for(int i=1;i<=n;i++) if(t[i]==0){
		t[i]=1;p[k]=i;sum+=dfs(k+1);t[i]=0;
	}
	return sum;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);getchar();
	char ch;for(int i=1;i<=n;i++) ch=getchar(),s[i]=ch-'0';for(int i=1;i<=n;i++) if(s[i]==1) la=i,su++,sm[i]=sm[i-1];else sm[i]=sm[i-1]+1;
	fac[0]=1;for(int i=1;i<=n;i++) scanf("%d",&c[i]),fac[i]=(fac[i-1]*i);
	if(su==0) {printf("0");return 0;}
	if(sm[n]==0) printf("%lld",fac[n]);
	else if(m==1){
		int ans=0;for(int i=1;i<=n;i++) if(c[i]>sm[la]) ans++;
		printf("%lld",ans*fac[n-1]%mod);
	}
	else printf("%d",dfs(1));
	return 0;
}
