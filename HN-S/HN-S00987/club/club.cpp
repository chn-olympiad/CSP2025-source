#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;//nd t cg
int T,n,cnt[5];
bool fa=true,fb=true;
struct node{
	int a,b,c,dab,dac,dbc;
}e[N];
vector<int> nbr[3];
bool cmp(node x,node y)
{
	if(x.a!=y.a)
	{
		return x.a>y.a;
	}
	if(x.b!=y.b)
	{
		return x.b>y.b;
	}
	if(x.c!=y.c)
	{
		return x.c>y.c;
	}
}
void solve()
{
	fa=true;
	fb=true;
	memset(cnt,0,sizeof cnt);
	cin>>n;
	for(int i=1;i<=3;i++)
	{
		nbr[i].clear();
	}
	for(int i=1;i<=n;i++)
	{
		cin>>e[i].a>>e[i].b>>e[i].c; 
		if(e[i].b!=0||e[i].c!=0)
		{
			fa=false;
		}
		if(e[i].c!=0)
		{
			fb=false;
		}
	}
	sort(e+1,e+n+1,cmp);
	int max1=0,ans=0;
	if(fa==true)
	{
		for(int i=1;i<=n/2;i++)
		{
			ans+=e[i].a;
		}
		cout<<ans<<endl;
	}
	else if(fb==true)
	{
		for(int i=1;i<=n;i++)
		{
			if(e[i].b>e[i].a&&cnt[2]<=n/2)
			{
				ans+=e[i].b;
				cnt[2]++;
			}
			else if(e[i].b<e[i].a&&cnt[1]<=n/2)
			{
				ans+=e[i].a;
				cnt[1]++;
			}
			else
			{
				ans+=e[i].c;
			}
		}
		cout<<ans<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			e[i].dab=abs(e[i].a-e[i].b);
			e[i].dac=abs(e[i].a-e[i].c);
			e[i].dbc=abs(e[i].b-e[i].c);	
		} 
		for(int i=1;i<=n;i++)
		{
			if(e[i].a==max(e[i].a,max(e[i].b,e[i].c)))
			{
				ans+=e[i].a;
				cnt[1]++; 
				nbr[1].push_back(i);
			}
			else if(e[i].b==max(e[i].a,max(e[i].b,e[i].c)))
			{
				ans+=e[i].b;
				cnt[2]++; 
				nbr[2].push_back(i);
			}
			else if(e[i].c==max(e[i].a,max(e[i].b,e[i].c)))
			{
				ans+=e[i].c;
				cnt[3]++; 
				nbr[3].push_back(i);
			}
		}
		while(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2)
		{
			for(int i=1;i<nbr[1].size();i++)
			{
				int j1=nbr[1][i];
				int j2=nbr[1][i-1];
				if(e[j2].dab<e[j1].dab)
				{
					cnt[1]--;
					cnt[2]++;
					ans-=(e[j2].a-e[j2].b);
				} 
				else if(e[j2].dac<e[j1].dac)
				{
					cnt[1]--;
					cnt[3]++;
					ans-=(e[j2].a-e[j2].c);
				}
			}
			for(int i=1;i<nbr[2].size();i++)
			{
				int j1=nbr[2][i];
				int j2=nbr[2][i-1];
				if(e[j2].dab<e[j1].dab)
				{
					cnt[2]--;
					cnt[1]++;
					ans-=(e[j2].b-e[j2].a);
				} 
				else if(e[j2].dbc<e[j1].dbc)
				{
					cnt[2]--;
					cnt[3]++;
					ans-=(e[j2].b-e[j2].c);
				}
			}
			for(int i=1;i<nbr[3].size();i++)
			{
				int j1=nbr[3][i];
				int j2=nbr[3][i-1];
				if(e[j2].dac<e[j1].dac)
				{
					cnt[3]--;
					cnt[1]++;
					ans-=(e[j2].c-e[j2].a);
				} 
				else if(e[j2].dbc<e[j1].dbc)
				{
					cnt[3]--;
					cnt[2]++;
					ans-=(e[j2].c-e[j2].b);
				}
			}
		}
		cout<<ans<<endl;
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		solve(); 
	}
	return 0;
}
