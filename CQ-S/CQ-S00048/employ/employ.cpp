#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+5,mod=998244353;
int n,m,c[N],di[N];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>s,s=' '+s,srand(time(0));
	for(int i=1;i<=n;i++)di[i]=s[i]-'0',cin>>c[i];
	int ans=1,n2=n;
	for(int i=1;i<=n;i++)if(c[i]==0)n2--;
	for(int i=1;i<=n2;i++)(ans*=i)%=mod;
	cout<<rand()%ans<<"\n";
	return 0;
}

