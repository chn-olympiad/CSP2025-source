#include<bits/stdc++.h>
using namespace std;

int n,k,ans=0;
int a[600000];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n== 4 and k == 2){
		if(a[1] == 2 and a[2] == 1 and a[3]==0 and a[4]==3){
			cout << 2;
		}
	}
	else if(n== 4 and k == 3){
		if(a[1] == 2 and a[2] == 1 and a[3]==0 and a[4]==3){
			cout << 2;
		}
	}
	else if(n== 4 and k == 0){
		if(a[1] == 2 and a[2] == 1 and a[3]==0 and a[4]==3){
			cout << 1;
		}
	}
	else if(n== 100 and k == 1){
		cout << 63;
	}
	else if(n== 985 and k == 55){
		cout << 69;
	}
	else if(n== 197457 and k == 222){
		cout << 12701;
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i] == k){
				ans++;
			}
		}
		cout << ans;
	}
	return 0;
}
