#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001];
long long ans=1;
char c;
int s[1001];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>c;
		s[i]=int(c-'0');
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int sum=1000,u=0;
		for(long long i=1;i<=n;i++){
			if(s[i]==1){
				sum=i;
				break;
			}
		}
		for(long long i=1;i<=n;i++){
			if(a[i]>=sum){
				u++;
			}
		}
		for(long long i=1;i<n;i++){
			ans*=i;
			ans%=998244353;
		}
		ans*=u;
		ans%=998244353;
		cout<<ans;
	}
	return 0;
}
