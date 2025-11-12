#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
#define ll long long 
ll n,k,sum,ans;
ll a[N];
bool f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int  i = 1;i<=n;){
		sum = a[i];
		if(a[i] == k){
		//	cout<<sum<<endl;
			ans++;
			i++;
			continue;
		}
		for(int j = i+1;j<=n;j++){
			//cout<<sum<<" ";
			sum = sum^a[j];
		//	cout<<a[j]<<" "<<sum<<endl;
			if(sum == k){
				i = j+1;
				ans++;
				if(j == n)f = 1;
				break;
			}
			if(j == n){
				i++;
				break;
			}
		}
		if(f)break;
		if(i == n)break;
	}
	printf("%lld",ans);
	return 0;
}
