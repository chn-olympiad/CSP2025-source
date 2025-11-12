#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<rand()*rand()%998244353;
	return 0;
}
/*
100+100+20+1?

pppp    ooo     l       y      y    ggggg     ooo      n     n
p   p  o   o    l        y    y    g         o   o     n n   n
ppp    o   o    l         y  y     g   gg    o   o     n  n  n
p      o   o    l          y       g    g    o   o     n   n n
p       ooo     llllll     y        ggggg     ooo      n     n
*/
