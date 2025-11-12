#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+5,M=4e6+5;
struct node{
	int u,v,val;
	node(int u=0,int v=0,int val=0):u(u),v(v),val(val){}
	bool operator<(const node &tmp)const{
		return val<tmp.val;
	}
};
node e[M];
node e0[M];
int to[11][N],vv[11],f[N];
int n,m,k;
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	f[x]=y;
}
int ksk(int len,int pn){
	sort(e+1,e+1+pn);
	int res=0;
	for(int i=1;i<=pn;i++){
		node p=e[i];
		if(find(p.u)!=find(p.v)){
			res+=p.val;
			merge(p.v,p.u);
			--len;
		}
		if(len==1){
			return res;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
//		int u,v,val;
//		cin>>u>>v>>val;
//		e0[i]=(node){u,v,val};
		cin>>e0[i].u>>e0[i].v>>e0[i].val;
		e[i]=e0[i];
	}
	int ff=0;
	for(int i=1;i<=k;i++){
		cin>>vv[i];
		if(vv[i]!=0)ff=1;
		for(int j=1;j<=n;j++){
			cin>>to[i][j];
		}
	}
	if(ff!=0)
	{
		int ans=INT_MAX;
		for(int s=0;s<(1<<k);s++){
//		cout<<s<<"\n";
			int lll=0;
			for(int i=1;i<=n+k;i++)f[i]=i;
			for(int i=1;i<=m;i++)e[++lll]=e[i];
			int base=0,len=n;
			for(int i=1;i<=k;i++){
				if((1<<(i-1))&s){
					base+=vv[i];++len;
					for(int j=1;j<=n;j++){
						e[++lll]=((node){i+n,j,to[i][j]});
					}
				}
			}
//		for(auto p:e){
//			cout<<p.u<<" "<<p.v<<" "<<p.val<<"\n";
//		}cout<<"\n";
			base+=ksk(len,lll);
			ans=min(ans,base);
		}
		cout<<ans;
	}
	if(ff==0)
	{
		int lll=m;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e[++lll]=(node){i+n,j,to[i][j]};
			}
		}
		for(int i=1;i<=n+k;i++)f[i]=i;
		cout<<ksk(k+n,lll);
	}
	return 0;
}