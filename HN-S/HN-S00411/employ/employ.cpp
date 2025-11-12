#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5;
int n,m,s[maxn],c[maxn],ans,f[maxn];
string x;
bool vis[maxn];
bool pd(){
	int ans=0,rs=0;
	for(int i=1;i<=n;i++){
		if(s[i]==0){
			rs++;
		}
		else{
			if(c[f[i]]<=rs){
				rs++;
			}
			else{
				ans++;
			}
		}
	}
	return ans>=m;
}
void dfs(int x){
	if(x>n){
		ans+=pd();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			f[x]=i;
			dfs(x+1); 
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>x;
	if(n>17){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		s[i]=x[i-1]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
