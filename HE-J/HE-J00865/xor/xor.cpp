#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
int n,k,a[N];
int ans = 0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		int cnt = a[i];
		for(int j = i+1;j <= n+1;j++){
			if(cnt == k){
				i = j-1;
				ans++;
				break;
			}
			cnt = cnt xor a[j];
		}
	}
	cout << ans;
	return 0;
}
