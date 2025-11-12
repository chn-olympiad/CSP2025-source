#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n,m,c[600],vis[501],ans;
string s;
vector<int>v;
void dfs(int id,int nu,int su){
	if(id>n){
		ans=ans+(su>=m);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			v.push_back(i);
			if(nu>=c[i]||s[id-1]=='0')dfs(id+1,nu+1,su);
			else dfs(id+1,nu,su+1);
			v.pop_back(); 
			vis[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		dfs(1,0,0);
		cout<<ans<<"\n";
		return 0;
	}
	return 0;
} /*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
