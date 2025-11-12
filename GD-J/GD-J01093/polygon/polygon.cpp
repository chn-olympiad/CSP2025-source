#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,l[10005],sum[10005],ans,maxn=-1;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	if(n<=3) {
		if(n<3){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			ans+=l[i];
			maxn=max(maxn,l[i]);
		} 
		if(ans<=2*maxn) cout<<0;
		else cout<<1;
		return 0;
	}
	else{
		cout<<0;
		return 0;
	}
	cout<<n;
	return 0;
}
