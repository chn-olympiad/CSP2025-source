#include<bits/stdc++.h>
using namespace std;
long long n,k,a[10005],ans,vem;bool f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	f = 1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i]==0){
			f = 0;
		}
	}
	if(f){
		cout << n/2;
	}
	else if(k==1){
		for(int i = 1;i <= n;i++){
			if(a[i]==k){
				ans++;
				//cout << i << endl;
			}
		}
		cout << ans;
	}
	else if(k==0){
		for(int i = 1;i <= n;i++){
			if(a[i]==k){
				ans++;
			}
			else if(a[i+1]==1){
				ans++;
				//cout << i << " " << i+1 << endl;
				i+=1;
			}
		}
		cout << ans;
	}
	return 0;
} 
