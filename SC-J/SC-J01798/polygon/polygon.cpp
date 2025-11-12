#include<bits/stdc++.h> 
using namespace std;
#define pq priority_queue
#define mkp make_pair
#define ll long long
/*
feropen
seat.ans
itn
mian
CCF
Genshin
y0
Never Gonna Give You UP~
guanzhu luogu@chenyuheng01 thank u miao~
put this in qipadaimadashang! I want to GO TV!
LOG:
[8:30]:start
[8:41]:T1 complete,start DEBUG
[9:30]:DEBUG complete(god d**med bug of map),T2 start
[9:47]:T2 complete,start DEBUG 
[9:50]:T2 complete,start T3
[10:00]:T3 start 30pts solver
[10:06]:30pts down,start 10pts
[10:11]10pts done
[10:19]:start T4 
[11:15]:T4 35pts done
*/ 
	int n;
int qwq[507];
string awa;int ret;
map<string,bool> mp;
int dfs(int stk,int mx,int sum)
{
	if(stk==0)
	{
		if(sum>mx*2&&(!mp[awa])) {mp[awa]=1;return 1;}
		else return 0;
	}
	int ret=0;
	int tmx=mx;
	for(int i=0;i<n;i++)
	{
		if(awa[i]=='0')
		{
			awa[i]='1';
			//cout<<i<<' ';
			mx=max(mx,qwq[i]);
			sum+=qwq[i];
			ret+=dfs(stk-1,mx,sum);
			awa[i]='0';
			mx=tmx;
			sum-=qwq[i];
		}
	}
	return ret;
}
int main()
{
	
	freopen("polygon.in","r",stdin);
	
	freopen("polygon.out","w",stdout);
	
	for(int i=0;i<507;i++) awa+='0';
	cin>>n;
	if(n<500)
	{
		for(int i=0;i<n;i++)
		{
			cin>>qwq[i];
		}
		ll ret=0;
		for(int i=3;i<=n;i++)
		{
			ret+=dfs(i,0,0);
			ret%=998244353;
		}
		cout<<ret;
		
	}
	else 
	{
		ll ret=0;
		ll tmp=1;
		ll div=1;
		for(int i=3;i<=n;i++)
		{
			for(int t=n;t>n-i;t--)
			{
				div*=t-n+i;
				div%=998244353;
				tmp*=t;
				tmp%=998244353;
			}
			tmp/=div;
			ret+=tmp;
			ret%=998244353;
			tmp=1;
			div=1;
		}
		cout<<ret;
	}
	return 0;
} 