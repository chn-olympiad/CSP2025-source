#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=0,c[510];
bool pd[510];
string s;
void dfs(ll x,ll y,ll p){
	ll pp=p;
	if(x==0||s[y-1]=='0'||y-pp>c[x]);
	else
		pp++;
	//cout<<x<<' '<<y<<' '<<pp<<endl;
	if(m-pp>n-y)
		return;
	if(y==n){
		if(pp>=m)
			ans++;
		return;
	}
	pd[x]=1;
	for(int i=1;i<=n;i++)
		if(pd[i]==0)
			dfs(i,y+1,pp);
	pd[x]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++)
		cin>>c[i];
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
