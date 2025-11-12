#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=501;

#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif

ll read()
{
	ll ans=0,flag=1;
	char c=gc();
	while(c<'0'||c>'9')
	{
		if(c=='-')flag=-1;
		c=gc();
	}
	while(c>='0'&&c<='9')
	{
		ans=ans*10+c-'0';
		c=gc();
	}
	return ans*flag;
}

int main()
{
	srand(time(0));
	freopen("employ.in","w",stdout);
	int n=5,flaga=1,flagb=0;
	cout<<n<<' '<<rand()%n+1<<endl;
	int cntb=0;
	for(int i=1;i<=n;i++)
	{
		if(flaga)cout<<1;
		else if(flagb)
		{
			if(cntb>18)
			{
				cout<<0;
				continue;
			}
			int res=rand()%2;
			cout<<res;
			cntb+=res;
		}
		else cout<<rand()%2;
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<rand()%(n+1);
		if(i<n)cout<<' ';
	}
	return 0;
}
