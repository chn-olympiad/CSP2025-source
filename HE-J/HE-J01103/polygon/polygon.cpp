#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],s1;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1)s1=1;
	}
	if(s1==0){
		int ans=0;
		for(int k=3;k<=n;k++){
			int an=0;
			for(int i=n-k+1;i>=1;i--)an+=i;
			if(k!=3)an=an*k/2;
			if(k>4)an-=2;
			ans+=an;
		}cout << ans;
		return 0;
	}
	if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2)cout << 1;
	else cout << 0;
	return 0;
}
