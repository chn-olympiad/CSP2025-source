#include <bits/stdc++.h>
using namespace std;
const int N=5000+666;
int n;
long long a[N];
long long ans=0;
signed main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		long long k=1,he=a[i],MAX=a[i];
		for(int j = i + 1 ; j <= n ; j++){
			k++,he+=a[j],MAX=max(MAX,a[j]);
			for(int q=j+1;q<=n;q++){
				k++,he += a[q],MAX=max(MAX,a[q]);
				if(k >= 3 && he > MAX * 2){
					ans++;
				}
			}
			k=2,he=a[j]+a[i],MAX=max(a[i],a[j]);			
		}
	}
	cout << ans;
	return 0;
}
