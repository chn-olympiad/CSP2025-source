#include<bits/stdc++.h>
using namespace std;
vector<int> nt[2][200010];
int t[2000010],ans,l,r;
string s1[200010],s2[200010];
void g(string P,int x,int y)
{
	int n=P.size(),i,j;
	i=0;
	j=-1;
	nt[y][x].push_back(-1);
	while(i<n)
	{
		if(P[i]==P[j]||j==-1)
		{
			i++;
			j++;
			nt[y][x].push_back(j);
		}
		else
			j=nt[y][x][j];
	}
}
void kmp(string S,string P,int x,int y)
{
	int n=S.size(),m=P.size(),i=0,j=0;
	while(i<n)
	{
		if(S[i]==P[j]||j==-1)
		{
			i++;
			j++;
		}
		else
			j=nt[y][x][j];
		if(j==m)
		{
			j=nt[y][x][j];
			if(t[i]==x&&(i-m-1)<=l&&i>=r)
				ans++;
			else
				t[i]=x;
		}
	}
}
int main()
{
	freopen("repalce.in","r",stdin);
	freopen("repalce.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q,i,j;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		g(s1[i],i,0);
		g(s2[i],i,1);
	}
	for(i=1;i<=q;i++)
	{
		ans=0;
		memset(t,0,sizeof(t));
		string t1,t2;
		cin>>t1>>t2;
		int a=t1.size(),b=t2.size();
		if(a!=b)
		{
			cout<<0<<'\n';
			continue;
		}
		l=-1;
		r=a;
		for(j=0;j<a;j++)
		{
			if(t1[j]==t2[j])
				l=j;
			else
				break;
		}
		for(j=a-1;j>=0;j--)
		{
			if(t1[j]==t2[j])
				r=j;
			else
				break;
		}
		for(j=1;j<=n;j++)
		{
			if(s1[j].size()<=a)
			{
				kmp(t1,s1[j],j,0);
				kmp(t2,s2[j],j,1);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
