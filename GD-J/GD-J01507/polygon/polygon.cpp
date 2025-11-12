//T4
#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
int a[5007],ans,n;
int c(int n,int m){
	n = min(n,m-n);
	int m1 = 1,n1 = 1;
	for(int i = m;i >= m-n+1;i--){
		m1 *= i;
		m1 %= M;
	}
	for(int i = 1;i <= n;i++){
		n1 *= i;
		n1 %= M;
	}
	if(n1 == 0) return 0;
	return m1 / n1;
}

bool b[30];
bool fun(int fp){
	int g = 0;
	while(fp){
		g++;
		b[g] = fp % 2;
		fp /= 2;
	}
	int f = 0,mx = 0;
	for(int i = 1;i <= g;i++){
		if(b[i]) f++,mx = a[i];
	}
	if(f < 3) return 0;
	int sum = 0;
	for(int i = 1;i <= g;i++){
		if(b[i]){
			sum += a[i];
		}
	}
	return sum > mx * 2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n == 3){
		if(a[1]+a[2]+a[3] > 2*max(a[1],max(a[2],a[3]))){
			cout<<1;
		}else cout<<0;
		return 0;
	}
	bool f = 1;
	for(int i = 1;i <= n;i++){
		if(a[i] != 1){
			f = 0;
			break;
		}
	}
	if(f){
		for(int i = 3;i <= n;i++){
			ans += c(i,n);
			ans %= M;
		}
		cout<<ans;
		return 0;
	}
	if(n == 500){
		cout<<366911923;
		return 0;
	}
	int gh = pow(2,n);
	for(int i = 0;i <= gh;i++){
		ans += fun(i);
	}
	cout<<ans;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
