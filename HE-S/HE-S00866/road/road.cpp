#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
ll n,m,k,ans,cnt;
struct st {
	ll x,y,w;
};
st a[N*100],a2[N*11];
ll c[20],b[20][N],p[N];
bool cmp(st x,st y) {
	return (x.w<y.w);
}
ll f(ll x) {
	if(p[x]!=x)p[x]=f(p[x]);
	return p[x];
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++) {
		p[i]=i;
	}
	for(int i=1; i<=m; i++) {
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		a[i]= {x,y,w};
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			ll x;
			scanf("%d",&x);
			b[i][j]=x;
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1; i<=m; i++) {
		if(f(a[i].x)!=f(a[i].y)) {
			p[f(a[i].x)]=f(a[i].y);
			ans+=a[i].w;
			a[++cnt]= {a[i].x,a[i].y,a[i].w};
		}
	}
	//cout<<ans<<endl;
	for(int i=1; i<(1<<k); i++) {
		ll x=i;
		for(int j=1; j<=cnt; j++) {
			a2[j]= {a[j].x,a[j].y,a[j].w};
		}
		ll cnt2=cnt,c1=0,ret=0;
		while(x) {
			c1++;
			if(x&1) {
				ret+=c[c1];
				p[c1+n]=c1+n;
				for(int j=1; j<=n; j++) {
					a2[++cnt2]= {c1+n,j,b[c1][j]};
					p[j]=j;
				}
			}
			x>>=1;
		}
		sort(a2+1,a2+cnt2+1,cmp);
		for(int j=1; j<=cnt2; j++) {
			if(f(a2[j].x)!=f(a2[j].y)) {
				p[f(a2[j].x)]=f(a2[j].y);
				ret+=a2[j].w;
			}
		}
		ans=min(ans,ret);
		//cout<<ret<<endl; 
	}
	cout<<ans;
	return 0;
}
