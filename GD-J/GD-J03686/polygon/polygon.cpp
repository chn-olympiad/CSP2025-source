#include<bits/stdc++.h>

using namespace std;

int n;
int a[5005];
vector<int> ans;
long long ansx;
const long long MOD=998244353;

bool chk()
{
	if(ans.size()<3)
	{
		return false;
	}
	int maxn=0;
	int sumn=0;
	for(int i=0;i<ans.size();i++)
	{
		maxn=max(maxn,ans[i]);
		sumn+=ans[i];
	}
	if(sumn>(maxn*2))
	{
		return true;
	}
	return false;
}

void dfs(int t)
{
	if(t==n)
	{
		if(chk())
		{
			ansx++;
		}
		return;
	}
	ans.push_back(a[t+1]);
	dfs(t+1);
	ans.pop_back();
	dfs(t+1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flg=0;
	//cout<<"here";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			flg=1;
		}
	}
	
	if(!flg)
	{
		//cout<<"here";
		for(int i=3;i<=n;i++)
		{
			long long nn=1;
			long long rr=1;
			for(int j=n;j>n-i;j--)
			{
				nn*=j;
				rr*=n-j+1;
			}
			//cout<<nn<<' '<<rr<<'\n';
			ansx+=(nn/rr);
			ansx%=MOD;
		}
		cout<<ansx;
		return 0;
	}
	dfs(0);
	cout<<ansx%MOD;
}
