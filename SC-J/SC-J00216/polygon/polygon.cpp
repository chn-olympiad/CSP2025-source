#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5010],N=998244353,sum,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				sum = a[i]+a[j]+a[k];
				if(sum > 2*a[k]) cnt = (cnt+1)%N;
			}
		}
	}
	cout << cnt;
	return 0;
}