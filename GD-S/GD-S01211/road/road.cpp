#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n,m,k; 
/*struct city{
	int u,v,w;
}a[1100000];*/
struct city{
	int w,u;
	int b;
}it;
vector <vector<city> >vc(11000);
struct con{
	int w;
	int c[11000];
}b[20];
bool vis_c[20]={0};
bool cmp(city A,city B){
	return A.w<B.w; 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&it.w);
		it.b=0;
		it.u=v;
		vc[u].push_back(it);
		it.u=u;
		vc[v].push_back(it);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&b[i].w);
		for(int j=1;j<=m;j++){
			scanf("%d",&b[i].c[j]);
			for(int e=1;e<j;e++){
				it.w=b[i].c[j]+b[i].c[e];
				it.u=j;
				it.b=i;
				vc[e].push_back(it);
				it.u=e;
				vc[j].push_back(it);
			}
		}
	}
	for(int i=1;i<=n;i++)sort(&vc[i][0],&vc[i][vc.size()-1],cmp);
	for(int i=1;i<=n;i++){
		for(int j=0;j<vc[i].size();j++){
			printf("%d %d %d\n",vc[i][j].u,vc[i][j].w,vc[i][j].b);
		}
		printf("\n");
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
