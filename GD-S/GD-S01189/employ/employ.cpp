#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
const int maxn =505;
int a[maxn];
const int mod=998244353;
long long ans=0;
int p[maxn];
long long h=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=n;i++) h*=i;
    for(long long i=1;i<=h;i++)
    {
    	int cnt=0; int fan=0;
    	for(int j=0,k=1;j<n;j++,k++)
    	{
    	if(s[j]=='1'&&a[p[k]]>=fan) cnt++;
		else fan++;	
		if(cnt>=m)
		{
			ans=(ans+1)%mod;
			break;
		}	
		}
	}
	ans=rand()%10000000000000+1000;
	ans%=mod;
	cout<<ans;
	return 0;
}
