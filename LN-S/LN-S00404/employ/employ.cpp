#include <bits/stdc++.h>
using namespace std;
int n,m,a[11],c[505];
bool v[11];
long long ans;
const long long mod=998244353;
char s[505];
void dfs(int d){
	if(d==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(i-cnt-1<c[a[i]]&&s[i]=='1')
				cnt++;
		if(cnt>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		a[d]=i;
		v[i]=1;
		dfs(d+1);
		v[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(n<=10){//1-2
		dfs(1);
	}else{
		ans=0;
	}
	printf("%lld",ans);
	return 0;
}

