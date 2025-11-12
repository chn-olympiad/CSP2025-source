#include <bits/stdc++.h>

using namespace std;
int n,m,k;
struct G{
	int u,v,w;
	bool operator  <(const G o)const{
	return w<o.w;
	}
};
G g[100005];
int a[10005],cur=1,sum,coun;
void kr(){
	for(int i=1;i<=coun;i++){
		a[i]=i;
	}
	for(int i=1;i<=coun;i++){
		int u=g[i].u,v=g[i].v;
		if(a[u]==a[v]){
			continue;
		}else{
			int idu=a[u],idv=a[v];
		for(int j=1;j<=coun;j++){
		if(a[j]==idu){
			a[j]=cur;
		}
		if(a[j]==idv){
			a[j]=cur;
		}
	}	
	sum+=g[i].w;
		}
	}
}
int main (){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    coun=m;
    for(int i=1;i<=m;i++){
    	cin>>g[i].u>>g[i].v>>g[i].w;
 
	}
	for(int i=m+1;i<=m+k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			count++;
			int W;
			cin>>W;
		    g[coun].u=i;g[coun].v=j;g[coun].w=W+x;
		}
	}
	sort(g+1,g+1+coun);
	kr();
	cout<<sum;
	return 0;
} 


