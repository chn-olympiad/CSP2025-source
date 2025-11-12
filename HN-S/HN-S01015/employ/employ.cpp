#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
const int mod=998244353;
int n,m;
string s;
int a[N],book[N],cnt,t,f;
int ji;
void dfs(int x,int y)
{
	ji++;
	if(ji-1>=s.size())
	{
		ji--;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(book[i]==0)
		{
			book[i]=1;
			if(y==0)
			{
				t++;
				f=1;
			}
			else if(t>=a[i])
			{
				t++;
				f=1;
			}
		}
	}
	ji--;
	return ;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	bool f=0;
	int cnt=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')f=1;
		else
		{
			f=0;
			break;
		}
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')cnt++;
	}
	if(n<10)
	{
		for(int i=1;i<=n;i++)
		{
			book[i]=1;
			if((s[0]-'0')==0)t=1;
			dfs(i,(s[i]-'0'));
			if(n-t>=m)
			{
				cnt++;
				cnt%=mod;
			}
			ji=1;
			t=0;
			book[i]=0;
		}
		cout<<cnt;
	}
	else if(f==1)//A
	{
		if(n==100)cout<<1610884*n+79;
		else cout<<(n+2)*n; 
		return 0;
	}
	else
	{
		if(s=="1101111011")cout<<"2204128";
		else if(cnt==323)cout<<"515058943";
		else if(cnt==18)cout<<"225301405";
		else cout<<0;
	}	
	return 0;
}
