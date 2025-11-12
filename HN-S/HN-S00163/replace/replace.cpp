#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
pair<string,string> p[N],que[N];
bool used[N];
int n,q,ans=0,f,num=1; 
int tgt;
bool check(int l,int r)
{
	if(used[tgt]) return 0;
	int j=0;
	for(int i=l;i<=r;i++)
	{
			if(que[num].first[i]!=p[f].first[j]) return 0;
			j++;
	}
	return 1;
}
void change(int l,int r)
{
	int j=0;
	for(int i=l;i<=r;i++)
	{
		que[num].first[i]=p[f].second[j];
		j++;
	}
}
bool check_ans()
{
	if(que[num].first==que[num].second) return 1;
	else return 0;
}
void dfs(int k)
{
	if(k>que[num].first.length()) return;
	if(check_ans) 
	{
		ans++;
		return ;
	}
	int cnt=0;
	for(int r=1;r<=k;r++)
	{
		for(int l=1;l<=r;l++)
		{
			for(f=1;f<=n;f++)
			{
				if(check(l,r))
				{
					change(l,r);
					tgt=f;
				} 
			}
			
		}
	}
	used[tgt]=1;
	dfs(k+1);
	used[tgt]=0;
	dfs(k+1);
}
void solve(int x)
{
	for(int i=1;i<=q;i++)
	{
		if(que[i].first.length()!=que[i].second.length());
		{
			cout<<'0'<<'\n';
			return;
		}
	}
	dfs(1);
	cout<<ans<<'\n';
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(f=1;f<=n;f++)
	{
		cin>>p[f].first>>p[f].second;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>que[i].first>>que[i].second;
	}
	for(num=1;num<=q;num++)
	{
		ans=0;
		solve(num);
	}	
	return 0;
} 
