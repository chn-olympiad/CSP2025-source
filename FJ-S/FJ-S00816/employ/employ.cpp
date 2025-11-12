#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int mod=998244353;
int n,m;
int a[510];
string s;
int ans=0;
bool st[510];
void dfs(int x,int y,int num){
	if(x>=n+1){
		if(num>=m){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(st[i]==0){
			st[i]=1;
			if(s[x]=='0'||y>=a[i]){
				dfs(x+1,y+1,num);
			}
			else
			{
				dfs(x+1,y,num+1);
			}
			st[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
