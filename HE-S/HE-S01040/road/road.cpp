#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct manbo{
	int u;
	int v;
	int w;
};
struct node{
	int c;
	int a[1100];
};
bool man(manbo a,manbo b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	manbo mb[100010];
	node c[15];
	cin>>n>>m>>k;

	int qq[n+1]={2},ent=0,op=n*2;
	for(int i=0;i<=n;i++){
		qq[i]=2;
	}
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&mb[i].u,&mb[i].v,&mb[i].w);
	}for(int i=0;i<k;i++){
		cin>>c[i].c;
		for(int j=0;j<n;j++){
			scanf("%d",&c[i].a[j]);
		}
	}sort(mb,mb+n,man);
	for(int i=0;i<m;i++){
		if(qq[mb[i].u]||qq[mb[i].v]){
			ent+=mb[i].w;
			//cout<<ent;
			qq[mb[i].u]--;
			qq[mb[i].v]--;
			op-=2;
		}if(op<=2){	
			break;
		}
	}cout<<ent;
	return 0;
}
