#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
string s;
int c[505];
int a[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		a[i]=i;
	}
	int fren=0;
	int ans=0;
	int now=0;
	int i=1;
	do
	{
		now=0;fren=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='1'&&fren<c[a[i]])
			{
				now++;
			}
			else fren++;
		}
		if(now>=m) ans=(ans+1)%MOD;
	}
	while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
}
