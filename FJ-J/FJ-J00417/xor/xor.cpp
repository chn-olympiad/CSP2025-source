#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int cnt=0;
			for(int k=i;k<=j;k++){
				cnt=(cnt^a[k]);
			}
			if(cnt==k){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
