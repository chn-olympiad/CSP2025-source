#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=510,p=998244353;
int c[N];
char ste[N],s[N];
int f[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i%p*f[i-1]%p;
	for(int i=1;i<=n;i++)cin>>ste;
	for(int i=1;i<=n;i++)s[i]=ste[i-1];
	for(int j=1;j<=n;j++)cin>>c[j];
	cout<<f[n];
	return 0;
}
