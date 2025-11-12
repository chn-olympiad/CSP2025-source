#include <bits/stdc++.h>
using namespace std;
int n,k,a[1145141],b[1145141],sum = 0;
bool vis[1145141] = {1};
bool check(int c){
	int maxn = -114514;
	int d = 0;
	for(int i = 1 ; i <= n + 1 ; i++) if(vis[i]) maxn = max(maxn,i-d-1),d = i;
	if(maxn >= c) return true;
	return false;
}
bool check2(int i,int j){
	for(int l = j ; l <= j + i ; l++) if(vis[l]) return true;
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		b[i] = b[i-1] ^ a[i];
	}
	vis[n+1] = 1;
	for(int i = 1 ; i <= n ; i++) if(a[i] == k) sum++,vis[i] = 1;
	for(int i = 1 ; check(i) && i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(check2(i,j)) continue;
			if((b[i+j] ^ a[j-1]) == k){
				sum++;
				for(int l = j ; l <= j + i ; l++) vis[l] = 1;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
