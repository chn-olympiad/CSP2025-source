#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e4+5,m=998244353;
int n,a[N],ans;
signed main() {
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1])
			continue;
		int cnt=0,num=0;
		for(int j=i-1;j>0;j++){
			num=(num+a[i])%m,cnt++;
			if(num>a[i])
				break;
		}
		if(num>a[i])
			ans=(ans+i-cnt+1)%m;
	}
	cout<<ans<<'\n';
	return 0;
}
