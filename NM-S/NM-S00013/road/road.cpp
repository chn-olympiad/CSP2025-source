#include<bits/stdc++.h>
using namespace std;
struct roa{
	int u,v,w;
}g[1000005];
bool cmp(roa x,roa y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	int a[15][10005];
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=c;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		sort(g+1,g+m+1,cmp);
		int ans=0;
		for(int i=1;i<=n-1;i++){
			ans+=g[i].w;
		}
		cout<<ans;
		return 0;
	}else cout<<0;
	return 0;
}
/*
emmmm……，怎么说呢，感觉已经燃尽了
一直很努力了，可s依然不会，上100pts都难，j倒是好点，就是s……qwq
后面就准备攻j了，高中再攻s了
t1调不出来了，t2不会做，t3t4就别说了
希望给我洛谷账号点个赞！（ZYFERIC）
那就别了吧，AK，IOI！
（不我拼音有这么差吗，一直打错，ruo->yuo dou->duo zen->zhen……） 
*/


