#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=21005;
const int MAXM=2010005;
struct Edge{
	int u,v,val;
}e[MAXM],ek[15][MAXN],eans[MAXN],etmp[MAXN];
int n,m,k,c[MAXN],cnt,cnt2,num;
int fa[MAXN];
void init(){
	for(int i=1;i<=n+k;i++)fa[i]=i;
}
int find(int id){
	if(fa[id]!=id)fa[id]=find(fa[id]);
	return fa[id];
}
void merge(int u,int v){
	u=find(u),v=find(v);
	fa[u]=v;
}
bool cmp(Edge a,Edge b){
	return a.val<b.val;
}
void add(int id){
	int j=1;
	int cntt=0;
	for(int i=1;i<=n;i++){
		while(j<=n+num-1&&eans[j].val<ek[id][i].val){
			etmp[++cntt]=eans[j];
			j++;
		}
		etmp[++cntt]=ek[id][i];
	}
	
	for(int i=1;i<=n+num-1+n;i++)eans[i]=etmp[i];
	/*for(int l=1;l<=n+num-1+n;l++)cout<<eans[l].u<<" "<<eans[l].v<<" "<<eans[l].val<<endl;
	cout<<endl;*/
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,val;
		cin>>u>>v>>val;
		e[i]={u,v,val};
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			ek[i][j]={i+n,j,0};
			cin>>ek[i][j].val;
		}
		sort(ek[i]+1,ek[i]+n+1,cmp);
	}
	int cnt=0;
	init();
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)!=find(v)){
			merge(u,v);
			e[++cnt]=e[i];
		}
	}
	int ans=LLONG_MAX;
	for(int i=0;i<=(1<<k)-1;i++){
		cnt2=0;
		int tmpans=LLONG_MAX,cc=0;
		num=0;
		for(int j=1;j<=k;j++)
			if((1<<(j-1))&i)num++;
		for(int j=1;j<=n-1;j++)eans[j]=e[j];
		for(int j=n;j<=n+num-1;j++)eans[j]={0,0,0};
		for(int j=1;j<=k;j++){
			if((1<<(j-1))&i){
				cc+=c[j];
				int ttmp=0;
				/*for(int l=1;l<=n+num-1;l++)cout<<eans[l].u<<" "<<eans[l].v<<" "<<eans[l].val<<endl;
				cout<<endl;*/
				add(j);
				init();
				/*for(int l=1;l<=n+num-1+n;l++)cout<<eans[l].u<<" "<<eans[l].v<<" "<<eans[l].val<<endl;
				cout<<endl;*/
				cnt=0;
				for(int l=1;l<=n+num-1+n;l++){
					int u=eans[l].u,v=eans[l].v;
					if(find(u)!=find(v)){
						merge(u,v);
						ttmp+=eans[l].val;
						eans[++cnt]=eans[l];
					}
				}
				tmpans=min(ttmp,tmpans);
			}
			
		}
		ans=min(ans,tmpans+cc);
	}
	cout<<ans<<endl;
	return 0;
}
