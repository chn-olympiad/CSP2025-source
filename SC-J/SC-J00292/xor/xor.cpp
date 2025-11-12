#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],now=1,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=now;j<=i;j++){
			if((sum[i]^sum[j-1])==k){
				ans++;
				now=i+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;//cccccccccccccccccccccccccc
}