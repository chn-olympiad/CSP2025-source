#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct e{
	ll s,e,w;
} ee[1100000],eee[1100000];
ll f[15][11000];
ll fa[11000];
ll n,m,k;
ll getfa(ll x){
	if(fa[x]==x)return x;
	return fa[x]=getfa(fa[x]);
}
ll u(ll a,ll b){
	ll x=getfa(a),y=getfa(b);
	if(x!=y)
	fa[x]=y;
	return 0;
}
bool cmp(e a,e b){
	return a.w<b.w;
}	
ll kk(int xx=m){
	int kkk=0;
	sort(ee,ee+xx,cmp);
	ll www=0;
	for(ll i=0;i<n;i++){
		fa[i]=i;
	}
	for(ll i=0;i<xx;i++){
		if(getfa(ee[i].s)!=getfa(ee[i].e)){
		u(ee[i].s,ee[i].e);
		www+=ee[i].w;
		kkk++;
		}
		if(kkk==n){
			return www;
		}
	}
	return www;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int AA=1;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		scanf("%lld%lld%lld",&eee[i].s,&eee[i].e,&eee[i].w);
	}
	int SS=0;
	for(int i=0;i<k;i++){
		SS=0;
		cin>>f[i][10090];
		if(f[i][10090]!=0)SS=1;
		for(int j=0;j<n;j++){
			scanf("%lld",&f[i][j]);
			//cin>>f[i][j];
			if(f[i][j]!=0)
				SS=1;
		}
		AA=min(AA,SS);
	}
	for(int i=0;i<n;i++){
		ee[i].s=eee[i].s;
		ee[i].w=eee[i].w;
		ee[i].e=eee[i].e;
	}
	if(k==0){
		cout<<kk();
		return 0;
	}
	if(AA==0){
		cout<<0;
		return 0;
	}
	int xx=1<<k;
	ll minn=114514114514ll;
	int kkkk=m;
	for(int pp=0;pp<xx;pp++){
		int i=pp;
		for(int j=0;j<n;j++){
			ee[j].s=eee[j].s;
			ee[j].w=eee[j].w;
			ee[j].e=eee[j].e;
		}
		int ff=0;
		int kkk=0;
		while(i!=0){
			if(i&1==1){
				for(int j=0;j<n;j++){
					ee[kkkk].s=kkk;
					ee[kkkk].w=f[kkk][j];
					ee[kkkk].e=j;
					kkkk++;
				}
				ff+=f[kkk][10090];
			}
			i>>=1;
		}
		minn=min(kk(kkkk)+ff,minn);
	}
	cout<<minn;
}