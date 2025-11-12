#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5003,MOD=998244353;
int ans,n,a[N],erc[35];
main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	erc[0]=1;
	for(int i=1;i<=30;i++)erc[i]=erc[i-1]*2;
	cin >>n;
	for(int i=1;i<=n;i++)cin >>a[i];
	int t=1;
	while(t!=erc[n]){
		int nextt=t+1,sum=0,cnt=0,maxx=-114514;
		for(int x=30;x>=0;x--){
			if(t>=erc[x]){
				t-=erc[x];
				sum++;
				cnt+=a[x+1];
				maxx=max(a[x+1],maxx);
			}
		}
		if(sum>=3&&maxx*2<cnt)ans++,ans%=MOD;
		t=nextt;
	}
	cout <<ans;
	return 0;
}
