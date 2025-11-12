#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,k;
int a[500010],sum[500010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie();
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		//cout<<sum[i]<<'\n';
	}
	sum[1]=a[1];
	int cnt=0;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			int ans=sum[j];
			ans^=sum[i-1];
			if(a[i]==k){
				//cout<<i<<" "<<j<<'\n';
				i++;
				cnt++;
			}
			else if(ans==k) {
				//cout<<i<<' '<<j<<" "<<sum[j]<<" "<<sum[i-1]<<" "<<ans<<'\n';
				i=j+1;
				cnt++;
			}
			
			
		}
	}
	cout<<cnt;
	return 0;
}
