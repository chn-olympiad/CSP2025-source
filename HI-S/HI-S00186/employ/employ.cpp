#include <bits/stdc++.h>
using namespace std;
const long long M=998244353;
int n, m;
char a[550];
int c[550];
int vis[550];
int cnt=0;
int ans=0;
int num[550];
void solve(int id){
	if(id==n+1){
		cnt=0;
		int k=0;
		for(int i=1;i<=n;i++){
			if(a[i-1]=='0'||k>=c[num[i]]){
				k+=1;
			}else{
				cnt+=1;
			}
		}
		if(cnt>=m)ans+=1;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		num[id]=i;
		vis[i]=1;
		solve(id+1);
		vis[i]=0;
	}
	return ;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin>>a;
	for(int i=1;i<=n;i++){
		scanf("%d", &c[i]);
	}
	int l;
	l=strlen(a);
	int flag=-1;
	for(int i=0;i<n;i++){
		if(a[i]=='0')flag=1;
	}
	if(flag==-1){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=M;
		}
		cout<<ans<<endl;
		return 0;
	}
	memset(vis, 0, sizeof(vis));
	solve(1);
	printf("%lld\n", ans);
	return 0;
}
