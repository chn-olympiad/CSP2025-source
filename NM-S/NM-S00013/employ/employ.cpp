#include<bits/stdc++.h>
using namespace std;
const int mod=99824435;
int n,m,p[505],c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	long long a=1,b=1,c=1;
	for(int i=1;i<=n;i++){
		a*=i;
	}
	for(int i=1;i<=m;i++){
		b*=i;
	}
	for(int i=1;i<=n-m;i++){
		c*=i;
	}
	cout<<((a/b)/c%mod);
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

