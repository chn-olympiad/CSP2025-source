#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[1000005];
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(int i = 1; i <= n; i++){
		if(a[i] == k){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
