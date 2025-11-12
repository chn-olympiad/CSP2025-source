#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500020];
int x[500020];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int cnt=0;
	for(int i=1;i<=n;i++){
		int sum=a[i];
		if(sum==k&&x[a[i]]==0){
			cnt++;
			x[a[i]]++;
		}
		for(int j=i+1;j<=n;j++){
			if((sum ^ a[j])==k&&x[a[j]]==0){
				cnt++;
				x[a[j]]++;
			}
			sum ^= a[j];
		}
	}
	cout<<cnt;
	return 0;
} 