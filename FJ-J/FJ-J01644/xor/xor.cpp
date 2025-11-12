#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000006],f[1000006];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,las=0,ans=0;
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}int s;
	for(int i = 1;i<=n;i++){
		s=a[i];
		if(s==k){
			ans++;
			las=i;
			continue;
		}
		for(int j = i-1;j>las;j--){
			s=(s^a[j]);
			if(s==k){
				las=i;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

