#include <bits/stdc++.h>
using namespace std;
int n,m,k,coast=0,num=0,ui=0,town[15],p[20000005],tto[2000005];
bool ttown[15];
struct ppo{
	int u,v,w;
	int ttoowwnn=0;
};
int find(int r){
	return p[r]==r?r:p[r]=find(p[r]);
};
bool cmp(ppo e,ppo q){
	return e.w<q.w;
}
ppo road[2000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>road[i].u>>road[i].v>>road[i].w;
		p[i]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>town[i];
		ttown[i]=1;
		for(int j=1;j<=m;j++){
			cin>>tto[j];
		}
		for(int j=1;j<=m;j++){
			for(int g=j+1;g<=m;g++){
				ui++;
				road[m+ui].u=i;
				road[m+ui].v=j;
				road[m+ui].w=tto[i]+tto[j]+town[i]/n;
				road[m+ui].ttoowwnn=i;
			}
		}
	}
	sort(road+1,road+(m+ui)+1,cmp);
	int fx,fy;
	for(int i=1;i<=m+k;i++){
		fx=find(road[i].u);
		fy=find(road[i].v);
		if(!(fx==fy)){
			p[fx]=fy;
			if(!(road[i].ttoowwnn==0)){
				coast-=(town[road[i].ttoowwnn]/n);
				if(ttown){
					coast+=town[road[i].ttoowwnn];
				}
			}
			coast+=road[i].w;
			num++;
		}
		if(num==n-1){
			cout<<coast;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
