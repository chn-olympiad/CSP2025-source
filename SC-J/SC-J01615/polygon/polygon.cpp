#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn=5050;
int n,a[maxn],sum=0,ans=-1;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	if(n<=2) cout<<0<<endl;
	else if(n==3){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		if(ans*2>=sum) cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}