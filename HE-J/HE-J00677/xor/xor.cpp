#include<bits/stdc++.h>
using namespace std;
long long n;
long long k;
long long a[500010];
long long num,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	num=0;
	for (int i=1;i<=n;i++){
		num = num^a[i];
		if (num == k){
			cnt+=1;
			num=0;
		}
	}
	cout << cnt;
	return 0;
}
