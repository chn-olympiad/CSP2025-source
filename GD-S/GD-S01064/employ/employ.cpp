#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,mod=998244353;
int n,m;
int q;
bool k=1;
int c[N];
string str;
bool used[N];
int lst[N];
int mapp[N];
int dfs(int k){
	if(k==n+1){
		for(int i=1;i<k;i++)mapp[i]=c[lst[i]];
		int tot=0;
		for(int i=1;i<k;i++){
			if(!(str[i]-'0')||tot>=mapp[i])tot++;
		}
		int num=k-1-tot;
		return num>=tot;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!used[i]){
			used[i]=1;
			lst[k]=i;
			ans+=dfs(k+1);
			used[i]=0;
		}
	}
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>str;
	str=" "+str;
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	printf("%lld",dfs(1));
	return 0;
}
