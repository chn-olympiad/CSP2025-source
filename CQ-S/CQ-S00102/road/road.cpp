#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10009],fa1[10009],kum;
int lb(int id){
	if(fa[id]==id){
		return id; 
	}
	else{
		return lb(fa[id]);
	}
}
struct node{
	int a,b,num;
}um[1000009];
struct node2{
	int a[10009];
}un[19];
bool cmp(node a,node b){
	return a.num<b.num;
}
int tst(int id){
	long long num=0;
	for(int i=1;i<=n;i++){
		if(fa[i]==i&&fa1[i]==0){
			int kid=0,mun=99999999;
			for(int i=1;i<=k;i++){
				if(un[i].a[n+3]!=id&&k!=un[i].a[n+2]){
					if(un[i].a[0]+un[i].a[n+1]+un[i].a[k]<mun){
						mun=un[i].a[0]+un[i].a[n+1]+un.a[i][k];
						kid=i;
					}
					else if(un.a[i][k]<mun){
						mun=un.a[i][k];
						kid=i;
					}
				}
			} 
			num+=mun;
			un[kid][n+3]=id;
		}
	}
	return num;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&um[i].a,&um[i].b,&um[i].num);
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
		fa1[i]=i; 
	}
	for(int i=1;i<=k;i++){
		un[i][n+1]=99999999;
		for(int j=0;j<=n;j++){
			scanf("%d",&un[i][j]);
			if(un[i][j]<un[i][n+1]){
				un[i][n+1]=un[i][j];
				un[i][n+2]=j;
			}
		}
	}
	sort(um+1,um+m+1,cmp);
	cout<<um[1].num;
	for(int i=1,y=0;y<n;i++){
		if(lb(um[i].a)!=lb(um[i].b)){
			fa[lb(um[i].a)]=fa[lb(um[i].b)]; 
			fa1[fa[lb](um[i].b)]=i;
			kum+=um[i].num;
		}
		num=min(num,tst(i)+kum);
	}
	printf("%lld\n",num);
	return 0;
} 
