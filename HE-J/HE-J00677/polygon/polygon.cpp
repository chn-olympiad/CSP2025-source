#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
long long cnt,b,maxn;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	long long bit = pow(2,n)-1;
	ans=0;
	for (int i=1;i<=bit;i++){
		cnt=0;
		b=pow(2,n-1);
		maxn=0;
		for (int j=1;j<=n;j++){
			long long o = i&b;
			if (o == b){
				cnt+=a[j];
				if (maxn < a[j]){
					maxn=a[j];
				}
			}
			b/=2;
		}
		if (cnt > 2*maxn){
			ans+=1;
			ans%998244353;
		}
	}
	cout << ans;
	return 0;
}
