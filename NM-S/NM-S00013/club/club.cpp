#include<bits/stdc++.h>
using namespace std;
struct people{
	int a,b,c;
};
bool cmp(people x,people y){
	if(x.a+x.b+x.c==y.a+y.b+y.c){
		int mixx=x.a+x.b+x.c-max({x.a,x.b,x.c})-min({x.a,x.b,x.c});
		int mixy=y.a+y.b+y.c-max({y.a,y.b,y.c})-min({y.a,y.b,y.c});
		if(max({x.a,x.b,x.c})==max({y.a,y.b,y.c})){
			if(mixx==mixy)return min({x.a,x.b,x.c})>min({y.a,y.b,y.c});
			else return mixx>mixy;
		}else return max({x.a,x.b,x.c})>max({y.a,y.b,y.c});
	}else return x.a+x.b+x.c>y.a+y.b+y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		people sum[100005]={0};
		for(int i=1;i<=n;i++){
			cin>>sum[i].a>>sum[i].b>>sum[i].c;
		}
		sort(sum+1,sum+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=sum[i].a;
		}
		cout<<ans;
	}
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

