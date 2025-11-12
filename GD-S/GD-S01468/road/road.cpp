#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+50;
ll n,m,k,fa[N],tt[1050],c[15],ans;
struct node{ll a,b,w;}e[N*100],v[1050][N],ve[15][N];
bool cmp(node x,node y){return x.w<y.w;}
ll find(ll x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0); 
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)cin>>e[i].a>>e[i].b>>e[i].w;
	sort(e+1,e+1+m,cmp);
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>ve[i][j].w;
			ve[i][j].a=i+n,ve[i][j].b=j;
		}
		sort(ve[i]+1,ve[i]+1+n,cmp);
	}
	for(ll i=1;i<=n;i++)fa[i]=i; 
	for(ll i=1;i<=m;i++){
		ll x=find(e[i].a),y=find(e[i].b);
		if(x!=y){
			ans+=e[i].w,fa[y]=x;
			v[0][++tt[0]]=e[i];
		}
	}
	for(ll i=1;i<(1<<k);i++){
		ll x=i,y,as=0,l=1,r=1;
		for(ll j=1;j<=k;j++){
			if((i>>(j-1))&1)as+=c[j],y=j;
		}
		x^=(1<<(y-1));
		for(ll j=1;j<=n+k;j++)fa[j]=j;
		while(l!=tt[x]+1||r!=n+1){
			if(l==tt[x]+1){
				ll X=find(ve[y][r].a),Y=find(ve[y][r].b);
				if(X!=Y){
					v[i][++tt[i]]=ve[y][r];
					as+=ve[y][r].w,fa[Y]=X;
				}
				r++;
			}
			else if(r==n+1||v[x][l].w<ve[y][r].w){
				ll X=find(v[x][l].a),Y=find(v[x][l].b);
				if(X!=Y){
					v[i][++tt[i]]=v[x][l];
					as+=v[x][l].w,fa[Y]=X;
				}
				l++;
			}
			else{
				ll X=find(ve[y][r].a),Y=find(ve[y][r].b);
				if(X!=Y){
					v[i][++tt[i]]=ve[y][r];
					as+=ve[y][r].w,fa[Y]=X;
				}
				r++;
			}
		}
		ans=min(ans,as);
	}
	cout<<ans;
	return 0;
}
