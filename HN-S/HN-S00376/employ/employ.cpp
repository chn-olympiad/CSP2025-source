/*
15:50 open
16:15 BF 1~2(must) 3~5(maybe)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IN "employ.in"
#define OUT "employ.out"
//#define DEBUG
const int maxn=505;
const int maxm=505;
const int mod=998244353;

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

char s[maxn];
int c[maxn];
int man[maxn];//每天去面试的都是谁 

bool check(int len,int target)
{
	//cerr<<endl;
	int didnt=0;//在第 i 人以前已有多少人被 pass 或弃权 
	int oks=0;//又有多少人“过关！” 
	for(int i=1;i<=len;i++)
	{
		if(s[i]=='0'||didnt>=c[man[i]])
		{
			//cerr<<"Day "<<i<<" Man "<<man[i]<<" Rejected..."<<endl;
			didnt++;
		}
		else if(s[i]=='1')
		{
			//cerr<<"Day "<<i<<" Man "<<man[i]<<" Pass!"<<endl;
			oks++;
		}
		if(oks>=target)
		{
			//cerr<<"Enough!"<<endl;
			return true;
		}
		//cerr<<oks<<' '<<didnt<<endl;
	}
	if(oks<target)
	{
		//cerr<<"Not Enough..."<<endl;
		return false;
	}
	//cerr<<endl;
}

int main()
{
	#ifndef DEBUG
	freopen(IN,"r",stdin);
	//freopen(OUT,"w",stdout);
	freopen("employerr.txt","w",stderr);
	#endif
	int n=read(),m=read();
	ll res=0;
	cin>>s+1;
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		man[i]=i;
	}
	/*
	for(int i=1;i<=n;i++)
	{
		cerr<<man[i];
		if(i<n)cerr<<' ';
	}
	cerr<<endl;
	*/
	if(check(n,m))res++;
	while(next_permutation(man+1,man+n+1))
	{
		/*
		for(int i=1;i<=n;i++)
		{
			cerr<<man[i];
			if(i<n)cerr<<' ';
		}
		cerr<<endl;
		*/
		if(check(n,m))
		{
			for(int i=1;i<=n;i++)
			{
				cerr<<man[i];
				if(i<n)cerr<<' ';
			}
			cerr<<endl;
			res++;
		}
	}
	cout<<res%mod<<endl;
	return 0;
}
