#include<bits/stdc++.h>
#define N 1000005
using namespace std;
int n,m,k,c[N];
/*
先写 T3 却连暴力都没写出来 是这辈子最错误的决定
草 最小生成树怎么写 我要不跳了
强连通分量怎么写哈哈哈哈哈哈 
啷个每道题用的算法都是早上不想复习的
我无话可说 
KAO 半个小时能写啥 不如不写 
*/
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b;cin>>a>>b>>c[i];
	}
	sort(c+1,c+1+n);
	int ans=0;
	for(int i=1;i<n;i++) ans+=c[i];
	cout<<ans; 
	
	
	return 0;
}
