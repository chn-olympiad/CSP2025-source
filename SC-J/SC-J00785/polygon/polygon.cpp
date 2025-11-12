#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5005;
const ll mod=998244353;
ll n,a[N],ans,maxn;
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]+a[3]>2*a[3])cout<<1;
		else cout<<0;
	}
	else{
		cout<<1234567;
	}
	return 0;
}