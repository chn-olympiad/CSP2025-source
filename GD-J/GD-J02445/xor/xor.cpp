#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,arr[200005];
	cin >> n >> k;
	for(int i = 0 ; i < n ; i++) cin >> arr[i];
	int sum = 0 , ans = 0;
	for(int i = 0 ; i < n ; i++){
		sum ^= arr[i];
		if(sum == k){
			ans++;
			sum = 0;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
