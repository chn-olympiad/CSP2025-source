#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[510];
int c[510],p[510];
long long ans=0;
bool a[510];
long long jie(int x){
	long long fan=1;
	for(int i=2;i<=x;i++){
		fan*=i;
		fan%=998244353;
	}
	return fan;
}
void dfs(int i,int f){
	if(i-f-1>=m){
		ans+=jie(n-i+1);
		ans%=998244353;
		return;
	}
	if(i>=n+1){
				return;
	}
	
	for(int j=1;j<=n;j++){
		if(a[j]){
			a[j]=false;
			int f2=f;
			if(s[i]=='0'||c[j]<=f)
				f2++;
			dfs(i+1,f2);
			a[j]=true;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	memset(a,true,sizeof(a));
	dfs(1,0);
	printf("%lld",ans);
	
	return 0;
}

