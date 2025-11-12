#include <bits/stdc++.h>
using namespace std;
int mx, k, n;
unsigned int a[1000100];
unsigned int f[1000100];
int m[1000100];
void dfs(int l, int d){
	if(m[l] != -1){
		mx = max(mx, d+m[l]);
		return;
	}
	mx = max(mx, d);
	if(l >= n)return;
	for(int r=l;r<n;r++){
		if(l == 0){
			if(f[r] == k){
				dfs(r+1, d+1);
			}
		}else{
			if((f[l-1]^f[r]) == k){
				dfs(r+1, d+1);
			}
		}
	}
	dfs(l+1, d);
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	memset(m, -1, sizeof(m));
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i == 0){
			f[i] = a[i];
		}else{
			f[i] = f[i-1] ^ a[i];
		}
	}
	for(int i=n-1; i>=0; i--){
		mx=0;
		dfs(i, 0);
		m[i] = mx;
	} 
	cout<<mx;
}
