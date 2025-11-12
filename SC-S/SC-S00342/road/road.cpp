#include<bits/stdc++.h>
using namespace std;
int n,m,k;

struct roa{
	vector<int>a;//编号 
	vector<int>b;//距离
	int sum; 
	bool uses;
};
roa city[10004];
int father[10004];
int midroad=0,ssum;
void pera(int s){
	if(ssum==n) return;
	else{
		int smindroad=0x3f3f3f3f,snext;
		bool y=0;
		for(int i=0;i<=city[s].sum;i++){
			if(city[s].b[i]<smindroad&&city[i].uses==0){
				smindroad=city[s].b[i];
				snext=city[s].a[i];
				y=1;
			}
		}
		if(!y){
			midroad+=smindroad;
			father[snext]=s;
			ssum++;
			pera(snext);
		}
		else if(father[s]==s) return;
		else pera(father[s]);
		return;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int s;
	for(int i=1;i<=n;i++) {
		city[i].sum=0;
		city[i].uses=0;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		city[u].a.push_back(v);
		city[v].a.push_back(u);
		city[u].b.push_back(w);
		city[v].b.push_back(w);
		city[u].sum++;
		city[v].sum++;
	}
	father[1]=1;
	pera(1);
	cout<<midroad;
}