#include<bits/stdc++.h>
using namespace std;
struct node{
	int cb;
	int ce;
	int cost;
};
struct cost3{
	int huafei;
	int kaiguan;
};
bool cmp(node a,node b){
	return a.cost<b.cost;
}
int main(){
	freopen("road1.in","r",stdin);
	freopen("road1.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	node rode[m+1];
	int town[k+1][n+10];
	cost3 towncost[k+2];
	for(int i=0;i<m;i++){
		cin>>rode[i].cb>>rode[i].ce>>rode[i].cost;
	}
	for(int i=0;i<k;i++){
		cin>>towncost[i].huafei;
		for(int j=0;j<n;j++){
			cin>>town[i][j];
		}
	}
	sort(rode,rode+m,cmp);
	int total=0,unbuild=0;
	if(m>=n){
		for(int i=0;i<n-1;i++){
			total+=rode[i].cost;
		}
		for(int i=0;i<k;i++){
			if(towncost[i].huafei>total){
				towncost[i].kaiguan=1;
				unbuild++;
			}
		}
		if(unbuild==k){
			cout<<total;
			return 0;
		}
	}
	
	
	
}
