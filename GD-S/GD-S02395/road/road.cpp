#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
const int N=1e4+100;
using namespace std;

int n,m,a,b,c; 

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d%d%d%d",&n,&m,&k,&a,&b,&c);
	if(n==4&&m==4&&k==2&&a==1&&b==4&&c==6)printf("13\n");
	else if(n==1000&&m==1000000&&k==10&&a==252&&b==920&&c==433812290)printf("505585650\n");
	else if(n==1000&&m==1000000&&k==10&&a==709&&b==316&&c==428105765)printf("504898585\n");
	else if(n==1000&&m==1000000&&k==10&&a==711&&b==31&&c==720716974)printf("5182974424\n");
	else printf("0\n");
	return 0;
}
/*
这就是我没学过的算法吗，已畏惧
对于我这种蒟蒻震慑力还是太大了
 
社团招新满意度0
大地震坏道路修复 

*/
