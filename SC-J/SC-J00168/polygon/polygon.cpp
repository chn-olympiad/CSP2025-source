#include<bits/stdc++.h>
using namespace std;
int n,k,ans,lr[10],lrl;
bool bo = true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int a[n];
	for(int i = 0;i < n;i ++){
		cin >> a[i];
		if(a[i] != 1){
			bo = false;
		}
	}
	if(k == 1){
		for(int i = 0;i < n;i ++){
			if(a[i] == 1) ans ++;
		} 
	}
	else if(k == 0 && bo) ans = n / 2;
	else if(k == 0 && !bo){
		for(int i = 0;i < n;i ++){
			if(a[i] == 0) ans ++;
		} 
	}
	cout << ans;
	return 0;
}