#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=998244353;
int c[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=1;
	scanf("%lld%lld",&n,&m);
	string str;
	cin>>str;
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]),ans=(ans*i)%M;
	int cnt1=0;
	for(int i=0;i<str.size();i++)
	 if(str[i]=='1') cnt1++;
	if(cnt1<m) printf("0\n");
	else printf("%lld\n",ans); 
	return 0;
}
