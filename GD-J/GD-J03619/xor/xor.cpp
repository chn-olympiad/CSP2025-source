#include <bits/stdc++.h>
using namespace std;

int n,k,a[500010];
void main2(){
	cin >> n >> k;
	bool fff=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i] != 1) fff = 0;
	}
	if(fff && k==0){
		cout << n/2;
		return;
	}else if(k==1){
		int ans = 0;
		for(int i=1;i<=n;i++){
			if(a[i] != a[i+1]){
				ans++;
				i++;
			}
		}cout << ans;
	}
	return;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	main2();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}  
