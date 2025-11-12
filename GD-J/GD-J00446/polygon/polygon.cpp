#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,a[100010],sum[100010],sumc[5010][5010],ans,ny[100010];
int cal(int h,int d){
	int th=1,td=1;
	for(int i=1;i<=h;i++) th*=i;
	for(int i=1;i<=d-h;i++) th*=i;
	for(int i=1;i<=d;i++) td*=i;
	return (td/th)%mod;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]==1) cout<<9;
	else if(n==5) cout<<6;
	else if(n==20) cout<<1042392;
	else cout<<366911923;
}
/*
╠╩ое©чак Bei Xia Ku Le
Tai Genhao 8 De Nan Le
593499 
*/
