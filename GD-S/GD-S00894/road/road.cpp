#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int ans=0,n,m,k,cn=0;
int c[15],f[N],l[15];

struct edge{
	int u,v,w;
} e[N];

int find(int x){
	if(f[x]==x) return x;
	f[x]=find(f[x]);
	return f[x];
}

void he(int x,int y){
	int zx=find(f[x]);
	int zy=find(f[y]);
	f[zx]=zy;
}

void gfy(){
	int bk=n-1,cnt=0;
	for(int i=1;i<=cn;i++){
		edge b=e[i];
		if(find(b.u)==find(b.v)) continue;
		if(c[b.u-n]==0){
			b.w-=l[b.u-n];
		}
		if(b.u>n&&c[b.u-n]!=0){
			c[b.u-n]=0;
			bk++;
		}
		ans+=b.w;cnt++;
		he(b.u,b.v);
		if(bk==cnt){
			break;
		}
	}
}

bool cmp(edge x,edge y){
	return x.w<y.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cn++;
		cin>>e[cn].u>>e[cn].v>>e[cn].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		l[i]=c[i];
		for(int j=1;j<=n;j++){
			cn++;
			e[cn].u=n+i;
			e[cn].v=j;
			cin>>e[cn].w;
			e[cn].w+=c[i];
		}
	}
	sort(e+1,e+cn+1,cmp);
	for(int i=1;i<=cn;i++) f[i]=i;
	gfy();
	cout<<ans;
	return 0;
}
