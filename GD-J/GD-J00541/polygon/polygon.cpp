#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s[5005];
long long cnt;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)
		s[i]=s[i-1]+a[i];
	for(int k=3;k<=n;k++){
		for(int i=0;i<=n-k;i++){
			if(s[i+k]-s[i]>a[i+k]*2){
				cnt++;
				cnt%=998244353;
			}
		}
	}
	cout<<cnt+n/2;
	
		return 0;
}

