#include<bits/stdc++.h>

using namespace std;
const int N=100,mod=998244353;
string s;
int a[N];
int n,m;
int path[N];
int tot;
int ans;
bool vis[N];
void check(){
	int cnt=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(cnt>=a[path[i]] || s[i-1]=='0')
			cnt++;
		else sum++;
	}
	if(sum>=m) ans=(ans+1)%mod; 
}
void dfs(int x){
	if(x==n+1){
		check();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			path[++tot]=i;
			vis[i]=1;
			dfs(x+1);
			tot--;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

