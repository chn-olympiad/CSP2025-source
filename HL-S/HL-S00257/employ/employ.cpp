#include<bits/stdc++.h>
using namespace std;
const int N=500+5;
const int mod=998244353;
int n,m,a[N];
unsigned long long ans=1;
string s;
int cnt;
int main() {
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=2;i--) {
		ans=(ans*i)%mod;
	}
	cout<<ans%mod;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}