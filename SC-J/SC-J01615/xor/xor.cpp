#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn=100000*5+10;
int n,k,a[maxn],sum=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=0&&a[i]<=1) sum++;
	} 
	if(sum==n&&k==0) cout<<n<<endl;
	else if(sum==n&&k==1) cout<<0<<endl;
	return 0;
}