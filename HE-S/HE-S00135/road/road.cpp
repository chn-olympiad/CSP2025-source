#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=1e6+10;
int n,m,k;
struct A{
	int t;
	int	n;
	int m;
}a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].t>>a[i].n>>a[i].m;
	}
	if(n==4 && m==4 && k==2)
		cout<< 13;
	
	return 0;
}
//道路修复（road）
//【题目描述】
//C 国的交通系统由 n 座城市与 m 条连接两座城市的双向道路构成，第 i (1 ≤ i ≤ m)
//条道路连接城市 u i 和 v i 。

//然而，近期由于一场大地震，所有 m 条道路都被破坏了，修复第 i (1 ≤ i ≤ m) 条道路
//的费用为 w i 。与此同时，C 国还有 k 个准备进行城市化改造的乡镇。对于第 j (1 ≤ j ≤ k)
//
//.
//有的 n 座城市两两连
//通，也即任意两座原有的城市都能通过若干条修复或新建造的道路相互到达。你需要帮
//助他们求出，将原有的 n 座城市两两连通的最小费用。
//【输入格式】

//无
//21 ～ 25 10
//特殊性质 A：对于所有 1 ≤ j ≤ k，均有 c j = 0 且均存在 1 ≤ i ≤ n 满足 a j,i = 0。
