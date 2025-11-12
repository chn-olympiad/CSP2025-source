#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+30;
int n,m,k;
struct node{
	int u,v;
	ll len,zl;
}e[N];
int cnt;
int fa[N];
ll ans;
bool v[N]={false};

bool cmp(node n1,node n2){
	return n1.len<n2.len;
}

int find(int x){
	return fa[x]=(fa[x]==x?x:find(fa[x]));
}

void hb(int x,int y){
	if(find(x)!=find(y)){
		fa[x]=y;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v;
		ll l;
		scanf("%lld%lld%lld",&u,&v,&l);
		e[i]={u,v,l,0};
	}
	int bi=m;
	int kk=0;
	//cout<<bi;
	for(int i=1;i<=k;i++){
		ll u;
		scanf("%lld",&u);
		for(int j=1;j<=n;j++){
			kk++;
			fa[kk]=kk;
			ll x;
			scanf("%lld",&x);
			bi++;
			e[bi]={n+i,j,x+u,u};
		}
	}
	sort(e+1,e+1+bi,cmp);
	/*for(int i=1;i<=bi;i++){
		cout<<e[i].len<<endl;
	}*/
	cnt=0;
	m=0;
	ans=0;
	while(cnt<=n){
		m++;
		int x=e[m].u;
		int y=e[m].v;
		int fx=find(x);
		int fy=find(y);
		if(fx!=fy){
			if(!v[x]){
				cnt++;
				if(x>n) ans-=e[m].zl;
			}
			if(!v[y]){
				cnt++;
				if(y>n) ans-=e[m].zl;
			}
			hb(x,y);
			v[x]=true;
			v[y]=true;
			ans+=e[m].len;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
