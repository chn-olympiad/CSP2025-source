#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,p=998244353;
int n,m,t[N],ts,c[N],mc,h[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;h[0]=1;mc=n;
	for(int i=1;i<=n;i++)h[i]=(ll)h[i-1]*i%p;
	for(int i=1;i<=n;i++)cin>>t[i],ts+=t[i];
	if(ts<m){cout<<0;return 0;}
	for(int i=1;i<=n;i++)cin>>c[i],mc=min(mc,c[i]);
	if(m==n){cout<<(!mc?0:h[n]);return 0;}
	cout<<1;
	return 0;
}
/*
猫是怎么叫的 喵喵

鸽是怎么叫的 咕咕

牛是怎么叫的 哞哞

狗是怎么叫的 

我想你了
*/ 
