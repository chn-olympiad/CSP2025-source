#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N=5e5+1013;
ll n,k;
ll a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	ll res=0,ans=0;;
	for(ll i=1;i<=n;i++){
		res^=a[i];
		if(res==k){
			ans++;
			res=0;
		}
	}
	cout<<ans;
	return 0;
}
/*
我想打洲
已经一个月没放假了qwq 
哈基米哦南北绿豆 


*/ 
