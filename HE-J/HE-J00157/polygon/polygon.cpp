#include<bits/stdc++.h>
using namespace std;
int n,a[5000]{0};
long long ans = 0;
void isp(int in){
	int vstp = -1,tp = 0;
	while(next_permutation(a,a+n)){
		for(int i = 0;i < in;i++){
			vstp = max(vstp,a[i]);
			tp += a[i];
		}
		if(tp > 2*vstp){
			ans++;
			tp = 0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 3;i <= n;i++){
		isp(i);
	}
	cout << ans % 998244353;
	return 0;
}
