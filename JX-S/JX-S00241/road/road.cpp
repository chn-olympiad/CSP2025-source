#include<bits/stdc++.h>
const int N=1e5+5,M=1e6+5;
#define int long long
using namespace std;
struct s{
	int u,v,w;
}l[(N+M)*2];

int n,m,k,f[N],tag,cnt,ans,a[15];
bool over[N];

bool cmp(s a,s b){
return (a.w<b.w);	
}

int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}

void bcj(){
	for(int i=1;i<=m+k*n;i++){
		if(find(l[i].u)!=find(l[i].v)){
			if(l[i].u<=n&&over[l[i].u]==0){
				tag++;
				over[l[i].u]=1;
			}
			if(l[i].v<=n&&over[l[i].v]==0){
				tag++;
				over[l[i].v]=1;
			}
			
			f[find(l[i].v)]=find(l[i].u);
			cout<<l[i].u<<' '<<l[i].v<<'\n';
			ans+=l[i].w;
		}
		if(tag==n)
		break;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)f[i]=i;
	
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		if(x>y)
		swap(x,y);
			l[i].u=x;
			l[i].v=y;
			l[i].w=z;
	}
	
	for(int i=1;i<=k;i++){
		int z;
		cin>>z;
		a[i]=z;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			l[m+(++cnt)].v=n+i;
			l[m+cnt].u=j;
			l[m+cnt].w=x;
		}
	}
	
	sort(l+1,l+m+cnt+1,cmp);
	bcj();
	cout<<ans;
	return 0;
	}
