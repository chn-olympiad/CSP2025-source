#include <bits/stdc++.h>
#define ffor(i,a,b) for(int i=(a);i<=(b);i++)
#define roff(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
//#define int long long
const int Maxn=1e4+27,Maxk=15,Maxm=1e6+2e5;
int n,m,k;
struct node
{
	int u,t,v;
}mp[Maxm],cp[Maxm];
bool cmp(node a,node b) {
	return a.v<b.v;
}
int a[Maxk][Maxn],fa[Maxn],cho[Maxn],c[Maxn];
bool vis[Maxk]; 
int get(int x) {
	int ans=0;
	while (x) {
		ans++;
		x/=2;
	}
	return ans;
}
int find(int x) {
	if (x==fa[x]) {
		return x;
	}
	return fa[x]=find(fa[x]);
}
void join(int x,int y){
	if (fa[find(x)]==fa[find(y)]) return;
	fa[find(x)]=fa[find(y)];
}
ll ans=0,sum=LONG_LONG_MAX;
int opt=0,cnt;
bool pd=1;
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	cin>>n>>m>>k;
	ffor(i,1,m) cin>>mp[i].u>>mp[i].t>>mp[i].v;
	ffor(i,1,m) {
		cp[i]=mp[i];
	}
	ffor(i,1,k) {
		cin>>c[i];
		if (c[i]!=0) pd=0;
		ffor(j,1,n) {
			cin>>a[i][j];
			if (a[i][j]) pd=0;
		}
	}
	if (pd) {
		cout<<0;
		return 0;
	}
	for(int i=0;i<=(1<<k)-1;i++) {
		ans=0;opt=0;
		ffor(j,1,k) vis[j]=false;
		for (int j=1;j<=get(i);j++) vis[j]=(bool(i&(1<<j-1)));
		ffor(j,1,k) if (vis[j]) ans+=c[j],cho[++opt]=j;
	    cnt=m;
	    ffor(j,1,opt) {
	    	ffor(K,1,n) mp[++cnt]=(node){n+cho[j],K,a[cho[j]][K]};
	    }  
	    sort(mp+1,mp+1+cnt,cmp);
	    ffor(j,1,n+k) fa[j]=j;
	    int tot=0;
	    ffor(j,1,cnt) {
	    	int x=mp[j].u,y=mp[j].t;
	    	if (find(x)==find(y)) {
	    		continue;
	    	}
	    	join(x,y);
	    	ans+=mp[j].v;
	    	++tot;
	    	if (tot==n+opt-1) break;
	    }
	    sum=min(sum,ans);
	    ffor(j,1,m) mp[j]=cp[j];
	}
	cout<<sum;
}
//g++ -std=c++14 -O2 road.cpp -o road 最好的情况有 55 pts 
