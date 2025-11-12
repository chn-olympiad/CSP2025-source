#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
	int from,to,w;
}bian[1100005],bian1[1100005];
bool cmp(node a,node b){
	return a.w<b.w;
}
int n,m,k,u,v,w,c[15],fa[10015];
int find(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);	
}
void hb(int x,int y){
	fa[x]=find(fa[y]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		bian[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>w;
			bian[m+(i-1)*n+j]={n+i,j,w};
		}
	}
	long long minx=1e18;
	for(int i=0;i<=(1<<k)-1;i++){
		int choose[15]={};
		int l=i;
		for(int j=k-1;j>=0;j--){
			if(l>=(1<<j)){
				choose[j+1]=1;
				l-=(1<<j);
			}
		}
		long long ans=0,aa=0;
		for(int j=1;j<=k;j++){
			ans+=choose[j]*c[j];
			aa+=choose[j];
		}
		//cout<<"ans:"<<ans<<endl;
		for(int j=1;j<=m;j++){
			bian1[j]=bian[j];
		}
		l=m+1;
		for(int j=1;j<=k;j++){
			if(choose[j]==1){
				for(int o=1;o<=n;o++){
					bian1[l]=bian[m+(j-1)*n+o];
					l++;
				}
			}
		}
		sort(bian1+1,bian1+l,cmp);
		int tot=0;
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
		for(int j=1;tot<n-1+aa;j++){
			u=bian1[j].from,v=bian1[j].to;
			if(find(u)!=find(v)){
				hb(u,v);
				hb(v,u);
				ans+=bian1[j].w;
				//cout<<j<<' '<<bian1[j].w<<' '<<ans<<endl;
				tot++;
			}
		}
	//	cout<<ans<<' ';
		minx=min(minx,ans);
		//cout<<minx<<endl;
	}
	cout<<minx;
	return 0;
}
//rp++
