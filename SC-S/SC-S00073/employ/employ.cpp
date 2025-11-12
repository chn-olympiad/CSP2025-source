#include<bits/stdc++.h>
using namespace std;
using ll=int;
ll l[1086]={0};
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m;
	long long t=1;
	cin>>n>>m;
	string a;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}for(int i=1;i<=n;i++){
		t*=i;
		t%=998244353;
	}cout<<t;
	return 0;
}