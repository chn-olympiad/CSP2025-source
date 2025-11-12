#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,k;
int v[N+5],a[N+5];
/*
n:原有的城市数量
m:道路数量
k:准备进行城市化改造的乡镇数量
v[i]:表示第i条道路连接的两座城市与修复该道路的费用
a[i]:第j个乡镇进行城市化改造的费用与在该乡镇与原有的城市间建造道路的费用
*/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>v[j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>a[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/* 
4 4 2

1 4 6
2 3 7
4 2 5
4 3 4

1 1 8 2 4
100 1 3 2 4
*/
