#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e4+5,M=1e6+5,M2=2e6+5;//k<=10
int n,m,k;
struct node{
	int u,v,w;
}arr[M];
node vt[M2];//A
int vrr[15];
int brr[15][N];
bool cmp(node a,node b){
	return a.w<b.w;
}
map<pair<int,int>,int> mp;
int res=0;
ll ans;
//还剩3分钟突然发现我写错了	我放弃 阴险狠毒的CCF 我就60tps吧！！！！！ 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&arr[i].u,&arr[i].v,&arr[i].w);
		vt[i].u=arr[i].u,vt[i].v=arr[i].v,vt[i].w=arr[i].w;//A
	}
	int cnt=m;
	for(int i=1;i<=k;i++){
		scanf("%d",&vrr[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&brr[i][j]);
			cnt++;
			vt[cnt].u=m+i,vt[cnt].v=j,vt[cnt].w=brr[i][j];
		}
	}
	//haochangshuru
	if(k==0){
		sort(arr+1,arr+m+1,cmp);
		for(int i=1;i<=m;i++){
			if(mp[{arr[i].u,arr[i].v}]==1||mp[{arr[i].v,arr[i].u}]==1) continue;
			mp[{arr[i].u,arr[i].v}]=1;
			res++;
			ans+=(ll)arr[i].w;
			if(res==n-1) break;
		}
		printf("%lld",ans);
		return 0;
	}
	int m1=m+k*n;
	sort(vt+1,vt+m1+1,cmp);
	for(int i=1;i<=m1;i++){
		if(mp[{vt[i].u,vt[i].v}]==1||mp[{vt[i].v,vt[i].u}]==1) continue;
		mp[{vt[i].u,vt[i].v}]=1;
		res++;
		ans+=(ll)vt[i].w;
		if(res==n+k-1) break;
	}
	printf("%lld",ans);
	return 0;
}
/*
会有重边？ 
*/ 
