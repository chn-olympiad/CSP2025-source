#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5010],maxn=-1,ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int sum=0;
	for(int i=3;i<=n;i++){
		for(int t=1;t<=n-i+1;t++){
			sum=0;
			maxn=-1;
			for(int j=t;j<=t+i-1;j++){
				cout << a[j] << ' ';
				sum+=a[j];
				if(a[j]>maxn){
					maxn=a[j];
				}
			}
			sum-=maxn;
			if(sum>maxn){
				ans++;
				ans%=998244353;
			}
			cout << endl;
		}
	}
	cout << ans;
    return 0;
}
