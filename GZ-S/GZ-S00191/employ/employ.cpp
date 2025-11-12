// GZ-S00191 贵阳市南明区双龙华麟学校 徐文景 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n;
	long long ans=n;
	for(int i=n-1;i>=2;i--){
		ans*=i;
		ans%=998244353;
	}
	cout << ans;
	return 0;
}
