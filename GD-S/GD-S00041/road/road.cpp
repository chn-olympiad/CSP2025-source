#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e4+100,M=1.1e6+10,B=10;
int n,m,k,f[1<<B][N];
using ll=long long;
ll tot[1<<B],res;
inline int find(int* f,int x){
	return x==f[x]?x:f[x]=find(f,f[x]);
}
inline bool merge(int* f,int x,int y){
	x=find(f,x),y=find(f,y);
	if(x==y)return false;
	f[y]=x;
	return true;
}
struct st{
	int typ,x,y,v;
	bool operator<(const st& ele)const{
		return v<ele.v;
	}
}ed[M];
int idx;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>ed[i].x>>ed[i].y>>ed[i].v;
		ed[i].typ=-1;
	}
	idx=m;
	for(int i=0,tmp,msk;i<k;i++){
		cin>>tmp;
		msk=((1<<k)-1)^(1<<i);
		tot[1<<i]+=tmp;
		for(int j=msk;j;j=(j-1)&msk)tot[j^(1<<i)]+=tmp;
		for(int j=1;j<=n;j++){
			idx++;
			cin>>ed[idx].v;
			ed[idx].x=n+i+1;
			ed[idx].y=j;
			ed[idx].typ=i;
		}
	}
	m+=k*n;
	sort(ed+1,ed+m+1);
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<=n+k;j++)f[i][j]=j;
	}
	for(int i=1,msk;i<=m;i++){
		if(find(f[0],ed[i].x)==find(f[0],ed[i].y))continue;
		if(ed[i].typ==-1){
			for(int j=0;j<(1<<k);j++){
				tot[j]+=merge(f[j],ed[i].x,ed[i].y)*ed[i].v;
			}
			continue;
		}
		tot[1<<ed[i].typ]+=merge(f[1<<ed[i].typ],ed[i].x,ed[i].y)*ed[i].v;
		msk=((1<<k)-1)^(1<<ed[i].typ);
		for(int j=msk;j;j=(j-1)&msk){
			// cout<<i<<' '<<(j^(1<<ed[i].typ))<<'\n';
			tot[j^(1<<ed[i].typ)]+=merge(f[j^(1<<ed[i].typ)],ed[i].x,ed[i].y)*ed[i].v;
		}
	}
	// for(int i=0;i<(1<<k);i++)cout<<tot[i]<<'\n';
	res=tot[0];
	for(int i=1;i<(1<<k);i++)res=min(res,tot[i]);
	cout<<res<<'\n';
}