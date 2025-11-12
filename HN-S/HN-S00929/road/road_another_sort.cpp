//15 21
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e4+5,M=1e6+5,K=10+5,E=2e6+5,P=2e4+5;
//<=6e8
//for(;;)++rp;
int n,m,k,c[N],a[K][N],fa[P];
struct node{
	int u,v,w;
}e[M],r[E],tmp[E],ke[K][N],tt[E];
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
void ms(node a[],int al,node b[],int bl,node c[]){
	int p1=1,p2=1;
	for(int i=1;i<=al+bl;i++){
		if(p2>bl||(p1<=al&&a[p1].w<=b[p2].w)){
			tmp[i]=a[p1];
			p1++;
		}
		else{
			tmp[i]=b[p2];
			p2++;
		}
	}
	for(int i=1;i<=al+bl;i++){
		c[i]=tmp[i];
	}
	return;
}
signed main(){
	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	freopen("road.ans","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		r[i]=e[i];
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			ke[i][j]={i+n+1,j,a[i][j]};
		}
	}
	int mini=1e18;
	sort(e+1,e+1+m,[](node a,node b){
		return a.w<b.w;
	});
	//0-index and 1-index, yay
	for(int i=0;i<(1<<k);i++){
//		cerr<<"$"<<endl;
		int rc=0,ans=0;
		for(int j=1;j<=m;j++){
			r[i]=e[i];
		}
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				ms(tt,rc,ke[j],n,tt);
				rc+=n;
				ans+=c[j];
			}
		}
		ms(r,m,tt,rc,r);
		rc+=m;
//		sort(r+1,r+1+rc,[](node a,node b){
//			return a.w<b.w;
//		});
		//I need to optimize this.
		for(int j=1;j<=n+k;j++){
//			fa[i]=i;
			fa[j]=j;
			//I'm shabby.
		}
		for(int j=1;j<=rc;j++){
//			cerr<<"!"<<r[j].u<<" "<<r[j].v<<" "<<r[j].w<<" "<<find(r[j].u)<<" "<<find(r[j].v)<<endl;
			if(find(r[j].u)!=find(r[j].v)){
				ans+=r[j].w;
				add(r[j].u,r[j].v);
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
