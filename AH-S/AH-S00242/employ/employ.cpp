#include<bits/stdc++.h>
using namespace std;
int n,m,ss,die;
long long Sum=0;
const int Mod=998244353;
int c[512],f[512],q[512],book[512],d,tmp;
string str;
vector<int>vec;
void dfs(int step)
{
	if(step==n+1)
	{
		die=0;
		ss=0;
		//for(int k=0;k<vec.size();k++)cout<<vec[k]<<' ';
		//cout<<'\n';
		for(int i=1;i<=n;i++)book[i]=0;
		die=0;
		ss=0;
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(book[j]!=0&&c[j]<=die)
				{
					book[j]=1;
					die++;
				}
			}
			if(book[vec[i]]==0)
			{
				if(str[i]=='1')
				{
					book[vec[i]]=1;
					ss++;
				}
				else if(str[i]=='0')
				{
					book[vec[i]]=1;
					die++;
				}
			}//cout<<"d:"<<die<<" a:"<<ss<<'\n';
			if(ss>=m)
			{
				Sum++;
				return;
			}
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			vec.push_back(c[i]);
			dfs(step+1);
			f[i]=0;
			vec.pop_back();
		}
	}return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>str;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}sort(c+1,c+1+n);
	dfs(1);
	cout<<Sum;
}
//Rhapsodie x Lacr1mosa forever
//Maybe... AFO
//I lose,but I never lost.
//hope 1=,but thats too hard
//the problems are in the hell.
//I really [CLEAN] CCF
//Good bye OI 2021.9.1~2025.11.1
