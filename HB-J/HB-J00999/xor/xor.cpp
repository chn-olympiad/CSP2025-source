#include<bits/stdc++.h>
using namespace std;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+1]={},sum[n+1]={},ans=0;
	bool b[n+1]={};
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(i==1)sum[i]=a[i];
		else sum[i]=a[i]^sum[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool flag=0;
			for(int t=i;t<=j;t++){
				if(b[t]){
					flag=1;
					break;
				}
			}if(flag)continue;
			if((sum[i-1]^sum[j])==k){
                for(int t=i;t<=j;t++)b[t]=1;
                ans++;
            }
		}
	}cout<<ans<<'\n';
	return 0;
}
