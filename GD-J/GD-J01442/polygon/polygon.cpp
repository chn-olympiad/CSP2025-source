#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,n,maxx;
ll a[5005];
int main(){
	freopen("poiygon.in","r",stdin);
	freopen("poiygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=3;i++){
		cin>>a[i];
		ans+=a[i];
		maxx=max(a[i],maxx);
	}
	if(maxx*2<ans)cout<<1;
	else cout<<0;
	return 0;
}
