#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int cnt;
long long n,k;
int sum;
long long ans;
int p;

int main(){
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1; i<=n;i++){
		cin >> a[i];
	}
	freopen("xor.in","r",stdin);
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++){
		if(a[i] == k){
			sum = 1;
			continue;
		}else{
			b[++cnt] == a[i];
		}
	}
	for(int i=1; i<cnt; i++){
		for(int j=i; j<cnt; j++){
			if(i == j){
				ans = a[j];
			}
			ans = max(ans & a[j+1],ans | a[j+1]);  
		}
		if(ans == k){
			sum = cnt - i;
		}
		ans = 0;
	}
	cout << sum;
    return 0;
}

