#include<bits/stdc++.h>
#define ll long long
#define e_b emplace_back
#define p_b push_back
#define fir frist
#define sec second
#define pii pair<int,int>
#define ios ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
const int N=101;
int n,m,ans;
string s;
int a[N];
bool vis[N];
void dfs(int p,int c,int sum){
	if(p==n+1){
		if(sum>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			if(s[p-1]=='0')dfs(p+1,c+1,sum);
			else{
				if(a[i]<=c)dfs(p+1,c+1,sum);
				else dfs(p+1,c,sum+1);
			}
			vis[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios;cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

