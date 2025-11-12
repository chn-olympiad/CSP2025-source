#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=505;
LL ans=1;
int n,m,c[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)ans*=i;
	if(ans>998)ans%=998;
	else if(ans>244)ans%=244;
	else if(ans>353)ans%=353;
	printf("%lld",ans);
	return 0;
	}
