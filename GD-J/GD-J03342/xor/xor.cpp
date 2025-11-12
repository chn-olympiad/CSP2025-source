#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,arr[1010],brr[1010][1010];
void f(int x,int y,long long s){
	if(y>n){
		ans = max(ans,s);
		return;
	}
	for(int i=y; i<=n; i++){
		if(brr[x][i]==k){
			f(i+1,i+1,s+1);
		}
	}
	ans = max(ans,s);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			brr[i][j] = brr[i][j-1] ^ arr[j];
		}
	}
	for(int i=1; i<=n; i++){
		f(i,i,0);
	}
	cout << ans;
	return 0;
} 
