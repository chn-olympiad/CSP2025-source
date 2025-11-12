#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5e4+5;

//创建一个链式前向星，然后选择一个城市集合出发，计算出可能潜在的道路总和价值， 选出最小的那条道路，然后再扩大范围
//一个进阶版的最小生成树写法？

struct Road{
	int u,v,w,w2;//w2为如果这条路需要城市化一个村庄，城市化村庄的费用 ,默认为0 
}road[300];

vector<int>head[100];

int cnt=1;
void add(int u,int v,int w,int w2){
	head[u][head[u].size()]=cnt;
	road[cnt].u=u;
	road[cnt].v=v;
	road[cnt].w=w;
	road[cnt].w2=w2;
	cnt++;
} 

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		add(u,v,w,0);
		add(v,u,w,0);
		
	}
	
	return 0;
}

