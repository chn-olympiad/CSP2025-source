#include<bits/stdc++.h>
using namespace std;
#define long long int
const int N = 1e5+9;
int arr[N],b[N],vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans = 0,cnt = 0;
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		if(arr[i] == k){
			ans++;
			vis[i] = 1;
		}
		if(i%2==0){
			cnt++;
			b[cnt] = arr[i]^arr[i-1];
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=cnt;j++){
			if(b[j]==k&&vis[j*2]!=1&&vis[j*2-1]!=1){
				vis[j*2] = 1;
				vis[j*2-1] = 1;
				ans++;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
