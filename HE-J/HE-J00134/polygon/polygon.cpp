#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+100,MOD=998244353;
int n,a[N],cnt,ans,sum;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		for(int i=1;i<=n;i++){
			ans+=a[i];
		}
		if(ans>a[3]*2){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	return 0;
}
