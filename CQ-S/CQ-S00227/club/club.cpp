/*
	·´»ÚÊ½Ì°ÐÄ 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Data
{
	int id,my;
	friend bool operator <(Data a,Data b)
	{
		return a.my<b.my;
	}
};

int t,n;
int a[100009][4];
int cnt[4];
multiset<Data>s[4];

int found(int i,int kind)
{
	int p1=0,p2=0,p3=0;
	if(cnt[1]<n/2&&kind!=1)
	{
		p1=a[i][1];
	}
	else
	{
		p1=a[i][1]-found(s[1].begin()->id,1);
	}
	
	if(cnt[2]<n/2&&kind!=2)
	{
		p2=a[i][2];
	}
	else
	{
		p2=a[i][2]-found(s[2].begin()->id,2);
	}
	
	if(cnt[3]<n/2&&kind!=3)
	{
		p3=a[i][3];
	}
	else
	{
		p3=a[i][3]-found(s[3].begin()->id,3);
	}
	
	return max({p1,p2,p3});
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	
	while(t--)
	{
		s[1].clear();
		s[2].clear();
		s[3].clear();
		
		int ans=0;
		
		cin>>n;
		
		queue<int>q;
		
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			q.push(i);
		}
		
		cnt[1]=cnt[2]=cnt[3]=0;
		
		while(!q.empty())
		{
			int i=q.front();
			q.pop();
			multiset<Data>k;
			k.insert({1,a[i][1]});
			k.insert({2,a[i][2]});
			k.insert({3,a[i][3]});
			
			multiset<Data>::iterator it;
			it=k.end();
			it--;
			
			int j=it->id;
		
			if(cnt[j]<n/2)
			{
				cnt[j]++;
				s[j].insert({i,a[i][j]});
				ans+=a[i][j];
				a[i][j]=0;
//				cout<<i<<' '<<j<<'\n';
			}
			else
			{
				int maxn=max({a[s[j].begin()->id][1],a[s[j].begin()->id][2],a[s[j].begin()->id][3]});
				if(a[i][j]+maxn>s[j].begin()->my)
				{
					q.push(s[j].begin()->id);
					ans+=a[i][j]-s[j].begin()->my;
					s[j].erase(s[j].begin());
					s[j].insert({i,a[i][j]});
					a[i][j]=0;
//					cout<<i<<' '<<j<<'\n';
				}
			}
		}
		
		cout<<ans<<'\n';
	}
	
	return 0;
}
