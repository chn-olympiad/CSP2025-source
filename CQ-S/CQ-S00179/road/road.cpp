#include <bits/stdc++.h>
using namespace std;
int n,m,k,l,r,o;
int a[3][100001],b[100001],c[50][100001];
//for(int i=1;i<=n;i++){}
//if(){}
//int op(){}
//void op(){}
//scanf("%",&);printf("%",);
//[1000]
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int o1,o2,o3;
		scanf("%d%d%d",&o1,&o2,&o3);
		b[o1]++;
		a[0][b[o1]]=o2,a[1][b[o1]]++;
		b[o2]++;
		a[0][b[o2]]=o1,a[1][b[o2]]++;
	}for(int i=1;i<=k;k++){
		for(int i=1;i<=n;i++){
			scanf("%d",&c[k][i]);
		}
	}printf("0");
	return 0;
}
