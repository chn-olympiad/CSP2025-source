#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,mod=998244353;
int n,m,ans=1,chk=1;
int c[N],f[N];
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	if(s.find('0')!=-1)chk=0;
	for(int i=1;i<=n;i++)
		cin>>c[i],ans*=i,ans%=mod,chk&=c[i]!='0';
	if(n<=10)
	{
		ans=0;
		for(int i=1;i<=n;i++)
			f[i]=i;
		do
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i-1]=='0')cnt++;
				else if(cnt>=c[f[i]])cnt++;
			}
			ans+=(n-cnt)>=m;
		}while(next_permutation(f+1,f+1+n));
	}
	cout<<(n==m?ans*chk:ans);
	return 0;
}

