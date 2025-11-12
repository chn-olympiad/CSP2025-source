#include<bits/stdc++.h>
#define N 505
#define int long long
using namespace std;
int n,m,a[N],ans[N],cnt,vis[N],res;
const int MOD=998244353;
char ch[N];
void dfs(int id){
	if(id==n+1){
		int sum=0,num=0;
		for(int i=1;i<=n;i++){
			if(a[ans[i]]<=sum||ch[i]=='0') sum++;
			else num++;
		}
		if(num>=m) cnt=(cnt+1)%MOD;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			ans[id]=i;
			dfs(id+1);
			vis[i]=0;
		}
	}
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch[i];
		if(ch[i]=='1') res++;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	if(res==n){
		cnt=1;
		int num=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=1) num++;
		}
		for(int i=1;i<=num;i++) cnt=cnt*i%MOD;
	}else dfs(1);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
