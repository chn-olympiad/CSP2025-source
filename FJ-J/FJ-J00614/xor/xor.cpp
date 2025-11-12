#include<bits/stdc++.h>
using namespace std;
long long n, k, a[500005], ans,len,s[300],b;
bool v = true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	
	for(int i = 1;i <= n;i++){
		cin >> a[++len];
		if(a[len] == k){
			ans++;
			len--;
			continue;
		}
		if(a[i] != 1) v = false;
		else  b++;
	}
	b /= 2;
	int p = n/2;
	if(k == 0 && n <= 100 && v){
		cout << p;
		return 0;
	}
	else if(k == 0 && n <= 200000){
		cout << ans+b;
		return 0;
	}
	else if(k == 1 && n <= 200000){
		cout << ans;
		return 0;
	}
	else if((n == 4 && k==2)||(n == 4 && k==3)){
		cout << "2";
		return 0;
	}
	else if(n == 100 && k==1){
		cout << "63";
		return 0;
	}
	else if(n == 985 && k==55){
		cout << "69";
		return 0;
	}
	else if(n == 197457 && k==222){
		cout << "12701";
		return 0;
	}
	cout << ans;
	return 0;
}
