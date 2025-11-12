#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
long long c[N],vis[N],ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt;
	cin>>n>>m;cnt=n;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(c+1,c+n+1);
	if(!c[1]){
		cnt=1;
		for(int i=2;i<=n;i++)
		{
			if(c[i]<=cnt)
				cnt++;
			else
				break;
		}
	}
	n=n-cnt;
	for(int i=1;i<=n;i++)
		ans=(ans*i)%mod;
	cout<<ans;
	return 0;
	
}
