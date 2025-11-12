#include <bits/stdc++.h>
using namespace std;
long long n,num[6000],ans,ans2;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	// a1,a2......an an is max. a1 + .... + an-1 > an = polygon
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i = 1;i <= n;i ++){
		cin >> num[i];
	}
	sort(num + 1,num + 1 + n,cmp);
	for(int i = 1;i <= n ;i ++){
		for(int j = i + 1;j <= n;j ++){
			for(int k = j + 1;k <= n;k ++){
				if(num[k] + num[j] > num[i]) ans++;
			}
		} 
	}
	for(int i = 1;i <= n ;i ++){
		for(int j = i + 1;j <= n;j ++){
			for(int k = j + 1;k <= n;k ++){
				for(int p = k + 1;p <= n;p ++){
					if(num[k] + num[j] + num[p] > num[i]) ans ++; 
				}
			}
		} 
	}
	for(int i = 1;i <= n ;i ++){
		for(int j = i + 1;j <= n;j ++){
			for(int k = j + 1;k <= n;k ++){
				for(int p = k + 1;p <= n;p ++){
					for(int x = p + 1; x <= n;x ++){
						if(num[k] + num[j] + num[p] + num[x] > num[i]) ans ++;
					}
				}
			}
		} 
	}
	cout << ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
