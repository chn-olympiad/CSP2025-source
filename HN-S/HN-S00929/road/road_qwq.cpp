//15 21
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e4+5,M=1e6+5,K=10+5,E=2e6+5,P=2e4+5;
//for(;;)++rp;
int n,m,k,c[N],a[K][N],fa[P];
struct node{
	int u,v,w;
}e[M],ne[E],tmp[E];
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void add(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		fa[x]=y;
	}
	return;
}
void ms(int a,int b){
	int p1=1,p2=a+1;
	for(int i=1;i<=b;i++){
		if(p2>b||(p1<=a&&e[p1].w<=ne[p2].w)){
			tmp[i]=e[p1];
			p1++;
		}
		else{
			tmp[i]=ne[p2];
			p2++;
		}
	}
	for(int i=1;i<=b;i++){
		ne[i]=tmp[i];
	}
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		ne[i]=e[i];
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int mini=1e18;
	sort(e+1,e+1+m,[](node a,node b){
		return a.w<b.w;
	});
	//0-index and 1-index, yay
	for(int i=0;i<(1<<k);i++){
		int rc=m,ans=0;
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				for(int l=1;l<=n;l++){
					ne[++rc]={n+j+1,l,a[j][l]};
//					cerr<<"#"<<j<<endl;
				}
				ans+=c[j];
			}
		}
		sort(ne+1+m,ne+1+rc,[](node a,node b){
			return a.w<b.w;
		});
		ms(m,rc);
		for(int j=1;j<=n+k;j++){
//			fa[i]=i;
			fa[j]=j;
		}
		for(int j=1;j<=rc;j++){
//			cerr<<"!"<<ne[j].u<<" "<<ne[j].v<<" "<<ne[j].w<<" "<<find(ne[j].u)<<" "<<find(ne[j].v)<<endl;
			if(find(ne[j].u)!=find(ne[j].v)){
				ans+=ne[j].w;
				add(ne[j].u,ne[j].v);
			}
		}
		mini=min(mini,ans);
//		cerr<<"@"<<i<<" "<<ans<<endl;
	}
	cout<<mini;
	//U r still outputing wrong answers!
	//What r u doing?!
	return 0;
}
//k<=10, that's great!
//This is wangboyue_740325@Luogu.
//I'm so shabby that I didn't notice Xiangzhen!=Chengshi.
//The machine I'm using is too slow!
//It used 35.69 sec to output road2.
