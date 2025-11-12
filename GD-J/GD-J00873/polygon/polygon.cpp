#include<bits/stdc++.h>
using namespace std;
long long n, ans = 0, a[5005], s[5005], mod = 998244353;
long long q, w, e;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n - 2;i++)
		for(int j = i + 1;j <= n - 1;j++)
			for(int k = j + 1;k <= n;k++)
				if(a[i] + a[j] + a[k] > 2 * max(a[i], max(a[j], a[k])))
					ans++;
	if(n >= 4){
		for(int i = 1;i <= n - 3;i++)
			for(int j = i + 1;j <= n - 2;j++)
				for(int k = j + 1;k <= n - 1;k++)
					for(int l = k + 1;l <= n;l++)
						if(a[i] + a[j] + a[k] + a[l] > 2*max(a[i],max(a[j],max(a[k],a[l]))))
							ans++;
	}
	if(n >= 5){
		for(int i = 1;i <= n - 4;i++)
		for(int j = i + 1;j <= n - 3;j++)
		for(int k = j + 1;k <= n - 2;k++)
		for(int l = k + 1;l <= n - 1;l++)
		for(int m = l + 1;m <= n;m++)
		if(a[i]+a[j]+a[k]+a[l]+a[m]> 2 * max(a[i], max(a[j], max(a[k], max(a[l], a[m])))))
		ans++;
	}
	cout << ans;
	return 0;
}
