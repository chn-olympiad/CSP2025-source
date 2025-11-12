#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int MOD=998244353;
int n,m,ans,s[505],c[505];
string xx;
bool used[505];
void dfs(int x,int cnt){
	if(x>n){
		if(cnt>=m){
			ans=(ans+1)%MOD;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]&&s[x-1]<c[i]){
			used[i]=1;
			if(xx[x-1]=='1') dfs(x+1,cnt+1);
			else dfs(x+1,cnt);
			used[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>xx;
	for(int i=0;i<n;i++){
		s[i+1]=!(xx[i]-'0')+s[i];
		//cout<<s[i+1]<<" ";
	} 
	for(int i=1;i<=n;i++){
		cin>>c[i];
		//cout<<s[i]<<endl;
	} 
	dfs(1,0);
	cout<<ans;
	return 0;
}
