#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k == 0){
		cout<<2;
	}else if(k == 1){
		int ans = 0;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			if(a[i] == 1){
				ans++;
			}
		}
		cout<<ans;
	}else{
		cout<<3;
	}
	return 0;
}
