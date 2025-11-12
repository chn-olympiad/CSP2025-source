#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=20;
char s[N];
int c[N];
int res[N];
int is[N];
int vis[N];
int n,m;
int ans;
const int mod=998244353;
void dfs(int st){
	if(st==n+1){
		//for(int i=1;i<=n;i++) cout<<res[i]<<" ";
		//cout<<"\n";
		memset(is,0,sizeof is);
		int an=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				is[res[i]]=1;
			}else{
				int cnt=0;
      			for(int j=1;j<=i;j++){
      				if(is[res[j]]==1){
      					cnt++;
					}
				}
				if(cnt>=c[res[i]]) is[res[i]]=1;
				else an++;
			}
		}
		//cout<<an<<"\n";
		if(an==m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			res[st]=i;
			dfs(st+1);
			vis[i]=0; 
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==n){
		int fl=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0') fl=1;
		}
		if(fl==1){
			cout<<0;
			return 0;
		}
		else{
			int ress=1;
			for(int i=1;i<=n;i++){
				ress=(ress*i+mod)%mod; 
			}
			cout<<ress;
			return 0;
		}
	}
	dfs(1); 
	cout<<ans;
	return 0;
}