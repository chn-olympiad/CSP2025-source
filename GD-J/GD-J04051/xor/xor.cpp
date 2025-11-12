#include <bits/stdc++.h>
using namespace std;

int n,k,ans,arr[500008],prefix[500008];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	prefix[0]=0;
	for(int i=1;i<=n;i++){
		cin >> arr[i];	
		prefix[i]=(prefix[i-1] xor arr[i]);
	}
	int s=1;
	for(int i=1;i<=n;i++){
		for(int j=s;j<=i;j++){
			if((prefix[i] xor prefix[j-1])==k){
				ans++;
				s=i+1;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
