#include<bits/stdc++.h>
using namespace std;
int n,m,ttt0tt,ans,fa[10001];
struct node{
	int u,v,l;
}e[1000001];
int get(int x){
	if(fa[x]==x)return x;
	fa[x]=get(fa[x]);
}
void merge(int x,int y){
	fa[get(x)]=fa[get(y)];
}
bool cmp(node x,node y){
	if(x.l==y.l)return 1;
	return x.l<y.l;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>ttt0tt;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].l;
		
		
	}
	sort(e+1,e+m+1,cmp);
	//for(int i=1;i<=m;i++)cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].l<<endl;
	for(int i=1;i<=m;i++){
		//cout<<i<<' '<<get(e[i].u)<<' '<<get(e[i].v)<<endl;
		if(get(e[i].u)!=get(e[i].v)){
			
			merge(e[i].u,e[i].v);
			
			//for(int j=1;j<=n;j++)cout<<fa[j]<<' ';
			//cout<<endl;
			ans+=e[i].l;
			//cout<<ans<<endl;
		}else continue;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 7 0
1 2 3
1 3 4
2 4 7
3 5 7
4 5 3
1 4 2
2 5 3
*/
