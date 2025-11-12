#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[1000007],sum[1000007],t[5000007],ans,la=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	t[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		
		//cout<<sum[i]<<' '<<(sum[i]^m)<<' '<<t[sum[i]^m]<<'\n';
		if(t[sum[i]^m]){
			for(int j=la;j<i;j++){
				t[sum[j]]--;
			}
			ans++;
			la=i;
		}
		t[sum[i]]++;
	}
	cout<<ans;
	return 0;
}