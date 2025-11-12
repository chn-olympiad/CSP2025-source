#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[1000005],f[1000005];
int cnt[1000005];
signed main(){ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int s=0;
	for(int i=1;i<=n;i++){
		s^=a[i];
		if(s==k)f[i]=1;
		if(cnt[s^k])f[i]=max(f[i],f[cnt[s^k]]+1);
		f[i]=max(f[i],f[i-1]);
		cnt[s]=i;
	}
	cout<<f[n];
	return 0;
}
//#Shang4Shan3Ruo6Shui4
