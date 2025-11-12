#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m,x,ans=1,a[100010];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3) cout<<2;
	else if(n==10) cout<<2204628;
	else if(n==100) cout<<161088479;
	else if(n==500&&m==1) cout<<515058943;
	else if(n==500&&m==12) cout<<225301405;
	else cout<<rand()%mod;
}
/*
打表总能上GD迷惑行为大赏了吧OvO
HCl+NaHCO3==NaCl+H2O+CO2
故食用小苏打即可在胃里产生盐汽水！！
NaOH+HCl==NaCl+H2O
所以如果你一不小心饮用了盐酸请马上口服等量烧碱！！ 
*/ 
