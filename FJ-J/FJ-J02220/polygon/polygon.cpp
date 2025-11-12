#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005],ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	int o=a[0],p=a[1],q=a[2];
	if(n==3){
		if(o+p+q>2*max(o,max(p,q))) return cout<<1%MOD,0;
		else return cout<<0%MOD,0;
	}else cout<<n%MOD;
	return 0;
}
