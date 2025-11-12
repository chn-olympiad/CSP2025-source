#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500005],k=1,sum,ans,b;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum^=a[i];
		int c=sum;
		if(c==b){
			k=i+1;
			ans++;
			sum=0;
			continue;
		}
		for(int j=k;j<=i;j++){
			if(c==b){
				k=i+1;
				ans++;
				sum=0;
				break;
			}
			c^=a[j];
		}
	}
	cout<<ans;
	return 0;
}
