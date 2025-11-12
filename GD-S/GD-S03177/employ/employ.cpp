#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a,b,c,d,e,f,g,h;
	a=b=c=d=e=f=g=h=1;
	for(int i=1;i<=n;i++) {
		a=(a*i)%998244353;
	}
	for(int i=m;i<=n;i++) {
		for(int j=1;j<=n-i;j++) {
			b=(b*j)%998244353;
		}
		c+=b;
	}
	c+=a;
	cout<<c%998244353;
	return 0;
}










/*
luogu id:*1*5*4*
I am GD-J03498?(maybe)
My opinion:=T3's opinion

要中考了，今年会是我最后一年参加csp吗，我明年还会回到OI之中吗？
I Love OI!
I Love CCF,for letting me to have a new 认知 to the difficulties of OI's problem to a 蒟蒻! 

OI!See You Again!

铥！
元 英镑
不能再写这些了，希望它们不会把我竞赛三年的生涯变成禁赛三年Shift+6   
keywords:
feropen
club.cpp
road.cpp
replace.cpp
employ.cpp
clud
clab
raod
repalce
repacle
empty
emplay
enploy
"r",stdout
"w",stdin
ccf
luogu
kkksc03
Ren5Jie4Di4Ling5%
AK
IOI
CSP
CSP-S
CSP-J
NOIp
NOI
APIO
ICPC
WC
freopen("D:\GD-S03177\club\employ.in","r",stdin);
freopen("D:\GD-S03177\club\employ.out","w",stdout);
*/
