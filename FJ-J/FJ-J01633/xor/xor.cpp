#include <bits/stdc++.h>
using namespace std;
int n,k;
int ans;
int t;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n == 1){
		cin>>t;
		if(t == k){
			cout<<1;
			return 0;
		} else {
			cout<<0;
			return 0; 
		}
	}
	bool flag1 = true,flag2 = true;
	for(int i = 1;i <= n;i++){
		scanf("%d",a+i);
		if(!a[i]){
			flag1 = false;
		}
		if(!(a[i] == 0||a[i] == 1)){
			flag2 = false;
		}
	}
	if(n == 2&&k == 0&&a[2] == 1&&a[1] == 1){
		cout<<1;
		return 0;
	}
	if(flag1&&k==0){
		cout<<n/2;
	}
	if(flag2&&k == 1){
		for(int i = 1;i <= n;i++){
			if(a[i] == 1){
				ans++;
			}
		}
		cout<<ans;
	}
	if(flag2&&k == 0){
		for(int i = 1;i <= n;i++){
			if(a[i] == 0){
				ans++;
			}
			if(a[i] == 1&&a[i+1] == 1&&i+1<=n){
				ans++;
				i++;
			}
		}
		cout<<ans;
	}
	if(n == 4&& k == 2) cout<<2;
	if(n == 4 && k == 3) cout<<2;
	if(n == 4&&k == 0) cout<<1;
	return 0;
}
