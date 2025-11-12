/*
16:35 open
17:15 1~4
17:24 A(12)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IN "club.in"
#define OUT "club.ans"
//#define DEBUG
const int maxn=1e5+7;
//const int maxm=;

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

ll arr[maxn][3];
ll rev[3][maxn];
ll plan[maxn];//每个人被分到哪里
ll ress[maxn];
ll cnt[4];

bool check(int len)
{
	if(2*cnt[1]>len||2*cnt[2]>len||2*cnt[3]>len)return false;
	else return true;
}

void dfs(int dep,int pos,int len,ll &res)
{
	plan[dep]=pos;
	cnt[pos]++;
	if(2*cnt[pos]>len)return;
	if(dep==len)
	{
		if(check(len))
		{
			ll sum=0;
			/*
			for(int i=1;i<=len;i++)
			{
				cerr<<plan[i];
				if(i<len)cerr<<' ';
			}
			cerr<<endl;
			for(int i=1;i<=3;i++)
			{
				cerr<<cnt[i];
				if(i<len)cerr<<' ';
			}
			cerr<<endl;
			*/
			for(int i=1;i<=len;i++)
			{
				sum+=arr[i][plan[i]];
			}
			//cerr<<sum<<endl;
			if(sum>res)
			{
				res=sum;
				for(int i=1;i<=len;i++)
				{
					ress[i]=plan[i];
				}
			}
		}
		return;
	}
	for(int i=1;i<=3;i++)
	{
		dfs(dep+1,i,len,res);
		cnt[i]--;
	}
	return;
} 

int main()
{
	#ifndef DEBUG
	freopen(IN,"r",stdin);
	freopen(OUT,"w",stdout);
	//freopen("cluberr.txt","w",stderr);
	#endif
	int T=read();
	while(T--)
	{
		memset(arr,0,sizeof(arr));
		memset(cnt,0,sizeof(cnt));
		memset(plan,0,sizeof(plan));
		//cerr<<"Case "<<T<<endl;
		int n=read(),flaga=1,flagb=1;
		ll res=-0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				arr[i][j]=read();
				if((j==2||j==3)&&arr[i][j]!=0)flaga=0;
				if(j==3&&arr[i][j]!=0)flagb=0;
				rev[j][i]=arr[i][j];
			}
		}
		if(flaga)
		{
			sort(rev[1]+1,rev[1]+n+1);
			for(int i=n;i>=n/2;i--)
			{
				res+=rev[1][i];
			}
			cout<<res;
			if(T)cout<<endl;
			continue;
		}
		dfs(0,0,n,res);
		cout<<res;
		/*
		for(int i=1;i<=n;i++)
		{
			cerr<<ress[i];
			if(i<n)cerr<<' ';
		}
		cerr<<endl;
		*/
		if(T)cout<<endl;
	}
	return 0;
}
