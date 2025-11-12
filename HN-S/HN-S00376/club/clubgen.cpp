#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+7;
const int modai=20001;

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
	freopen("club.in","w",stdout);
	int T=1;
	cout<<T<<endl;
	while(T--)
	{
		int n=6,flaga=0,flagb=1;
		cout<<n<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if((j==2&&j==3)&&flaga)cout<<0;
				else if(j==3&&flagb)cout<<0;
				else cout<<rand()%modai;
				if(j<3)cout<<' ';
			}
			if(i<n)cout<<endl;
		}
		if(T)cout<<endl;
	}
	return 0;
}
