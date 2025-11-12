#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans,n,k,a[500010],b[500010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]++;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			b[i]=0;
			continue;
		}
		int sum=0;
		for(int j=i;j<=n;j++){
			if(j==i){
				sum=a[j];
				continue;
			}
			sum=sum^a[j];
			if(sum==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
