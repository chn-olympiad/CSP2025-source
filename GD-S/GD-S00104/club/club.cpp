#include<bits/stdc++.h>
#define ll long long
#define R register
#define PII pair<int,int>
#define mk(x,y) make_pair(x,y)
using namespace std;
const int N=1e5+5;
struct node{ll a,b,c;}a[N];
int n,b[N],tot;
vector<int> g[3];
inline void solve(){
	cin>>n;ll sum=0;tot=0;
	g[0].clear();g[1].clear();g[2].clear();
	for(R int i=1;i<=n;++i){
		cin>>a[i].a>>a[i].b>>a[i].c;
		int mx=max({a[i].a,a[i].b,a[i].c});
		if(mx==a[i].a){
			g[0].emplace_back(i);
		}else if(mx==a[i].b)g[1].emplace_back(i);
		else g[2].emplace_back(i);
		sum+=mx;
	}
	int len1=g[0].size(),len2=g[1].size(),len3=g[2].size();
	if(len1<=n/2&&len2<=n/2&&len3<=n/2){
		cout<<sum<<'\n';
	}else{
		if(len1>n/2){
			for(R int i=0;i<len1;++i){
				b[++tot]=max(a[g[0][i]].b,a[g[0][i]].c)-a[g[0][i]].a;
			}
			sort(b+1,b+tot+1,[&](int x,int y){return x>y;});
			int del=len1-n/2;
			for(R int i=1;i<=del;++i)sum+=b[i];
		}else if(len2>n/2){
			for(R int i=0;i<len2;++i){
				b[++tot]=max(a[g[1][i]].a,a[g[1][i]].c)-a[g[1][i]].b;
			}
			sort(b+1,b+tot+1,[&](int x,int y){return x>y;});
			int del=len2-n/2;
			for(R int i=1;i<=del;++i)sum+=b[i];
		}else{
			for(R int i=0;i<len3;++i){
				b[++tot]=max(a[g[2][i]].b,a[g[2][i]].a)-a[g[2][i]].c;
			}
			sort(b+1,b+tot+1,[&](int x,int y){return x>y;});
			int del=len3-n/2;
			for(R int i=1;i<=del;++i)sum+=b[i];
		}
		cout<<sum<<'\n';
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _;cin>>_;while(_--)solve();
	return 0;
}