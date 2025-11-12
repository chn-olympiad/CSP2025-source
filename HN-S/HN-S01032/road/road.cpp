#include<bits/stdc++.h>
using namespace std;
#define MAXN 2000005
#define N 10025
#define ll long long
int fa[N];
ll ans;
struct ed{
	int u,v;
	ll w;
}a[MAXN],b[MAXN];
int n,m,k;
ll cnt;
ll minn;
ll num;
ll c[N];
struct node{
	ll id;
	ll w;
}tt[12][MAXN];
int findf(int x){
	if(fa[x]==x)return x;
	return fa[x]=findf(fa[x]);
}
bool cmp(ed x,ed y){
	return x.w<y.w;
}
bool cmp2(node x,node y){
	return x.w<y.w;
}	
ed ff[MAXN];
void add(int x){
	for(int i=1;i<=num;i++)ff[i]=a[i];
	int l=1,r=1;
	for(int i=1;i<=num+n;i++){
		if(l<=num&&(r>n||ff[l].w<=tt[x][r].w)){
			a[i]=ff[l];
			l++;
		}
		else {
			a[i].u=x+n;
			a[i].v=tt[x][r].id;
			a[i].w=tt[x][r].w;
			r++;
		}
	}
	num+=n;
}
void kruskal(int f){
	int flag=0;
	int l=1,r=1;
	while(flag<f-1){
		if(l<=cnt&&(r>num||b[l].w<=a[r].w)){
			//cout<<l<<" ";
		//	cout<<b[l].u<<" "<<b[l].v<<" "<<b[l].w<<endl;
			int fu=findf(b[l].u);
			int fv=findf(b[l].v);
			if(fu!=fv){
				fa[fu]=fv;
				ans+=b[l].w;
				flag++;
			}
			l++;
		}
		else{
			//cout<<a[r].u<<" "<<a[r].v<<" "<<a[r].w<<endl;
			int fu=findf(a[r].u);
			int fv=findf(a[r].v);
			if(fu!=fv){
				fa[fu]=fv;
				ans+=a[r].w;
				flag++;
			}
			r++;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int fu=findf(a[i].u);
		int fv=findf(a[i].v);
		if(fu==fv)continue;
		else{
			b[++cnt].u=a[i].u;
			b[cnt].v=a[i].v;
			b[cnt].w=a[i].w;
			fa[fu]=fv;
			minn+=a[i].w;
			//cout<<b[cnt].u<<" "<<b[cnt].v<<" "<<b[cnt].w<<endl;
		}
	}
	//cout<<minn<<endl;
	for(int j=1;j<=k;j++){
		scanf("%lld",&c[j]);
		for(int i=1;i<=n;i++){
			ll x;
			scanf("%lld",&tt[j][i].w);
			tt[j][i].id=i;
		}
		sort(tt[j]+1,tt[j]+1+n,cmp2);
	}
	for(int i=1;i<(1<<(k));i++){
		//cout<<i<<" ";
		num=0;
		ans=0;
		int f=n;
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=0;j<k;j++){
			//cout<<(1<<j)<<" ";
			if((1<<j)&i){
				ans+=c[j+1];
				f++;
				add(j+1);
			}
		}
		//for(int i=1;i<=num;i++)cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;
		//sort(a+1,a+1+num,cmp);
		kruskal(f);
		minn=min(minn,ans);
		//cout<<ans<<endl;
	}
	printf("%lld",minn);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
