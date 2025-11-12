#include<bits/stdc++.h>
#define ll long long
using namespace std;
int rd(){int x=0;char ch=getchar();while(!isdigit(ch)) ch=getchar();while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();return x;}
const int N=1e5+10;
int n,a[3][N],c[3];
bool vis[N];

struct node{
	ll v;int id,op;
	
	friend bool operator<(const node &x,const node &y){return x.v<y.v;}
};

ll sol(int d){
	ll ans=0,res=0;
	c[0]=c[1]=c[2]=0;
	c[d]=n;
	for(int i=1;i<=n;i++) vis[i]=0;
	priority_queue<node> q;
	for(int i=1;i<=n;i++){
		res+=a[d][i];
		for(int j=0;j<3;j++) if(j!=d) q.push({a[j][i]-a[d][i],i,j});
	}
	while(!q.empty()){
		node x=q.top();q.pop();
		if(vis[x.id]||c[x.op]==n/2) continue;
		vis[x.id]=1,c[x.op]++,c[d]--;
		res+=x.v;
		if(c[d]<=n/2) ans=max(ans,res);
	}
	return ans;
}

void solve(){
	n=rd();
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++) a[j][i]=rd();
	}
	printf("%lld\n",max(sol(0),max(sol(1),sol(2))));
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=rd();
	while(t--) solve();
	return 0;
}
