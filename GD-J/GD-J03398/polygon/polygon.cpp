#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],ans;
const int MOD=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<pow(2,n);i++){
		int t=i,wei=0,sum=0,maxx=0;
		while(t){
			int weizhi=t&1;
			wei++;
			if(weizhi==1){
				sum+=a[wei];
				maxx=max(maxx,a[wei]);
			}
			t=t>>1;
		}
		if(sum>2*maxx) ans=(ans+1)%MOD;
	}
	cout<<ans;
	return 0;
}
