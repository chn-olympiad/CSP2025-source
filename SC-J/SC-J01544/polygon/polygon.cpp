#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,a,b,c,maxn;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>a>>b>>c;
	maxn=max(max(a,b),c);
	if((a+b+c)>maxn*2)cout<<1;
	else cout<<0;
	return 0;
}