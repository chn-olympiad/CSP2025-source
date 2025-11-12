#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,mod=998244353;
int n,m,c[N],p[N],ans=0;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;++i)
		scanf("%d",c+i);
	for(int i=0;i<n;++i)
		p[i]=i+1;
	do
	{
		int cnt=0;
		for(int i=0;i<n;++i)
		{
			if(s[i]=='0')
				++cnt;
			else if(cnt>=c[p[i]])
				++cnt;
		}
		if(n-cnt>=m)
		{
			++ans;
			ans%=mod;
		}
	}while(next_permutation(p,p+n));
	printf("%d",ans);
	return 0;
}
