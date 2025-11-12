#include<iostream>
#include<stdio.h>
#include<algorithm>
#define N 505
using namespace std;
const int mod=998244353;
int n,m;
char s[N];
int c[N];
int p[N];
int ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
        p[i]=i;
    do
    {
    	int fail=0,success=0;
    	for(int i=1;i<=n;i++)
    	{
    		if(fail>=c[p[i]]||s[i]=='0')
    		    fail++;
    		else
    		    success++;
		}
		if(success>=m)
		    ans=(ans+1)%mod;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}
