#include <bits/stdc++.h>
using namespace std;

int family[100011],n,m,k;
bool vis[11]={};
long long c[11],c1[11][100001],sum=0;
struct node{
	int u,v;
	long long value;
}b[10000001];

void init(){
	for(int i=1;i<=n;i++){
		family[i]=i;
	}
}
int find(int x){
	if(x!=family[x]) find(family[x]);
	return family[x];
}
int unite(int x,int y){
	if(find(x)==x){
		family[x]=find(y);
	}else{
		family[y]=find(x);
	}
	
}
bool connected(int x,int y){
	return find(x)==find(y);
}
bool arr(node i,node j){
	return i.value<j.value;
}
int main(){
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

	cin>>n>>m>>k;
	init();

	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].value;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>c1[i][j];
		}
	}
	sort(b,b+m+1,arr);
	int u,v;
	bool flag;
	for(int i=0;i<m;i++){
		u=b[i].u;
		v=b[i].v;
		flag=false;
		if(connected(u,v)){
			continue;
		}else{
			for(int j=1;j<=k;j++){
				
				if(b[i].value>=c[j]+c1[j][u]+c1[j][v] && !vis[j] ){
					for(int o=1;o<=n;o++){
						if(connected(o,v) && c1[j][o]<c1[j][v]){
							v=o;
						}
					}
					for(int l=1;l<=n;l++){
						b[m+1+l].u=n+j;
						b[m+1+l].v=l;
						b[m+1+l].value=c1[j][l];
						
					}
					m+=n;
					sort(b,b+m+1,arr);
					
					flag=0;
					vis[j]=true;
					family[n+j]=n+j;
					unite(n+j,v);
					unite(u,n+j);
					sum+=c[j]+c1[j][u]+c1[j][v];
					break;
				}else{	
					flag=true;
				}
			
			}
			if(flag){
				unite(u,v);
				sum+=b[i].value;
			}
			
		}
		
	}

	cout<<sum;
}

