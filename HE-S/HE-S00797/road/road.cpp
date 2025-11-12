#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,s=0,ans=0;
int a[15][10005];
int u[1000005],v[1000005],w[1000005];
int f[1000005],Robin[1000005];
int main(){
	//洛谷：finner_forgeter 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		Robin[u[i]]=min(Robin[u[i]],w[i]);
		Robin[v[i]]=min(Robin[v[i]],w[i]);
		s+=w[i];//所需要的最大价值 
	}for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}//很明显，这道题我并不会做
	// T1打了2.5h，感觉自己还是太颓废了 
	for(int i=1;i<=n;i++){
		ans+=Robin[i];
		//突然一想自己两年前也挺强的，虽然只是相对而言 
		//只考虑没有村庄（有村庄肯定不会写
		/*
			找出来重复提到的城市取多条道路的最小值
			 预测<=12pts 
		*/ 
		
	}cout<<ans;
	return 0;
}
