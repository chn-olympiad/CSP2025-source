#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500007],s[500007],t[500007],l,r,ans;
bool check(int l,int r){
	for(int i = l;i <= r;i ++) if (t[i]) return false;
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		s[i] = a[i] ^ s[i - 1];
	}
	int i = 1;
	while(i <= n){
		while(i <= n && t[i]) i ++;
		for(int j = i;j <= n;j ++){
			if ((s[j] ^ s[i - 1]) == k && check(i,j)){
				ans ++;
				for(int w = i;w <= j;w ++){
					t[w] ++;
				}
				i = j;
			}
		}
	}
	cout << ans;
	return 0;
} 
