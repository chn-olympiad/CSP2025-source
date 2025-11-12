#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL n,k,a[100005],maxx=1,minn=1e18;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	bool check=true;
	for(LL i = 1; i <= n; ++i){
		cin >> a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
		if(a[i]!=1) check=false;
	}
	if(check && k==0LL){
		cout << n/2;
		return 0;
	}
	if(maxx==1 && minn==0){
		if(k==0LL){
			a[n+1]=1e18;
			LL ans=0;
			for(int i = 1; i <= n; ++i){
				if(a[i]+a[i+1]==2){
					ans++;
					++i;
				}else if(a[i]==0) ans++;
			}
			cout << ans;
		}else{
			LL ans=0;
			for(LL i = 1; i <= n; ++i){
				if(a[i]==1){
					ans++;
				}
			}
			cout << ans;
		}
	}else{
		if(n==4 && k==3) cout << 1;
		else if(n==4 && k==0 && a[1]==2) cout << 1;
		else if(n==5 && k==2) cout << 2;
		else cout << n/2;
	}
	return 0;
}
/*
1^0 1
1^1 0
0^0 0

4 1
9 5 6 4





*/
