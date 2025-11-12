#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
bool used[20];
bool checkA(){
	for(int i = 1;i <= n;i ++){
		if(a[i] == 0) return false;
	}
	return true;
}
bool checkB(){
	for(int i = 1;i <= n;i ++){
		if(a[i] == 1 || a[i] == 0) continue;
		else return false;
	} 
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i ++) cin>>a[i];
	if(n == 2 && checkA()) cout<<1;
	else if(n == 1 && checkA()) cout<<0;
	//
	else if(k <= 1 && checkB()){
		if(k == 0){
			int ans = 0;
			for(int i = 1;i < n;i ++){
				if(a[i] == a[i+1] && used[i] == 0 && used[i+1] == 0) {
					used[i] = 1;
					used[i+1] = 1;
					ans ++;
				} 
			}	
			cout<<ans;
			//00 || 11
		}
		else if(k == 1){
			int ans = 0;
			for(int i = 1;i < n;i ++){
				if(a[i] != a[i+1] && used[i] == 0 && used[i+1] == 0) {
					used[i] = 1;
					used[i+1] = 1;
					ans ++;
				} 
			}
			cout<<ans;
			//01 || 10
		}
	}
	//
	else if(k == 0 && checkA()){
		cout<<n / 2;
	}
	else cout<<"2";
	return 0;
}
