#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[5050], cnt, mx=-1;
bool f[5050];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> a[i], mx=max(mx,a[i]);
	if(mx==1)
		cnt = n*(n-1)%998244353*(n-2)%998244353;
	else {
		for(int i=1; i<(1<<n); i++){
			ll mx_1=-1, sum=0, t=0;
			for(int j=0; j<n; j++)
				if(int(i&(1<<j))!=0)
					f[j+1]=1;
				else
					f[j+1]=0;
			for(int k=1; k<=n; k++)
				if(f[k])
					t++,sum+=a[k], mx_1=max(mx_1,a[k]);
			if(t>=3&&sum>2*mx_1)
				cnt=(cnt+1)%998244353;
		}
	}
	cout << cnt;
	return 0;
}
