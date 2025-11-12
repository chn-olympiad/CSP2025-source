#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e3+5,mod=998244353;

queue<int> q;
int n,a[maxn],ans,maxa;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		maxa=max({a[1],a[2],a[3]});
		if((a[1]+a[2]+a[3])>maxa*2){
			cout<<1;
		}else cout<<0;
	}
	return 0;
}