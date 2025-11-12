#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)cin >> a[i];
	int lst = 1,cnt = 0;
	while(lst <= n){
		bool f = false;
		long long sum = 0;
		for(int j = lst;j <= n;j++){
			if(j == lst)sum = a[j];
			else sum ^= a[j];
			if(sum == k){
				lst = j + 1;
				cnt++;
				f = true;
				break;
			}
		}
		if(!f)lst++;
	}
	cout << cnt << endl;
	return 0;
}
