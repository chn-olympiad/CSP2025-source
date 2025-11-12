#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[1000005],book[100005],ans,n,m;
vector<int>qwq;
string s;
bool cheak()
{
	int cnt=0,qq=0,qaq=0;
	for(auto i:qwq)
	{
		++qaq;
		if(s[qaq]=='0') 
		{
			cnt++;
			continue;
		}
		else
		{
			if(cnt>=a[i])
			{
				cnt++;
				continue;
			}
			qq++;
		}
	}
	return qq>=m; 
} 
void dfs(int x)
{
	if(x==n+1)
		ans+=cheak();
	for(int i=1;i<=n;++i)
	{
		if(book[i]==1)
			continue;
		book[i]=1;
		qwq.push_back(i);
		dfs(x+1);
		book[i]=0;
		qwq.pop_back();
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	if(n<=20)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(ans<m)
	{
		cout<<0;
		return 0;
	}
	long long answer=1;
	for(int i=1;i<=n;++i)
		answer=answer*i%mod;
	cout<<answer;
}
/*
3 2
101
1 1 2


10 5
1111111111
6 123 4 2 1 2 5 4 3 3

*/
