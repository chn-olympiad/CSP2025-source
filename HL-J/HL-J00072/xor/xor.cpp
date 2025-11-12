#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,q=-1;
const int N=5e5+55;
long long a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		int z=a[q++];
		if(q==n){
			break;
		}
		if(z==k){
			ans++;
			continue;
		}	
		for(int o=q+1;o<n;o++){
			if(z==k){
				ans++;
				q=o;
				break;
			}
		}
	}
	cout << ans+1;
	return 0;
}
