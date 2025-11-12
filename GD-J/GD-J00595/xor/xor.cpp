#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+7;
int n,k,ans;
int a[N],sum[N];
int main(){
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout); 
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
		if(sum[i]==k){
			sum[i]=0;
			ans++;
		}
	}
	cout << ans;
	return 0;
}

