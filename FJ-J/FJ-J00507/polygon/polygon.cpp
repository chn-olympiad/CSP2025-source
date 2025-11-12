#include<bits/stdc++.h>
using namespace std;
long long n,a[10010],sum=0,mx=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if(sum>2*mx) cout<<1;
	else cout<<0;
	return 0;
}

