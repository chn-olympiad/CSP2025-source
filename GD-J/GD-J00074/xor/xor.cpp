#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5*1e5;
int n,k;
ll a[N],sum[N];
bool check(ll x){
	int cnt=0;
	int i=1,j=1;
	while(j<=n){
		if(sum[i]==k){
			j++; cnt++;
		}
		else if(sum[j]^sum[i]==k){
			i=j;
			j++;
			cnt++;
		}
		else{
			j++;
		}
	}
	return cnt>=x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	if(k==0){
		cout<<n/2;
		return 0;
	}
	ll l=1,r=n,ans=0;
	while(l<=r){
		ll mid=l+((r-l)>>1);
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<ans;
	fclose(stdout);
	fclose(stdout);
	return 0;
}

