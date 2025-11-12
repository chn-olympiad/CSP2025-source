#include<bits/stdc++.h>
//#define LL long long

using namespace std;

typedef long long LL;
typedef pair<LL,pair<LL,LL>> piii;

const LL N=100010;

LL n;
vector<LL> w[N];
vector<pair<LL,LL>> s[N];
LL x[4];
struct Node
{
	LL c,id,id1;
	bool operator <(const Node t)const
	{
		return c<t.c;
	}
};

bool cmp1(vector<LL> t1,vector<LL> t2)
{
	LL maxa=0,maxaa=0,maxb=0,maxbb=0;
	for(LL i=0;i<3;i++)
	{
		if(t1[i]>=maxa)maxaa=maxa,maxa=t1[i];
		else if(t1[i]>maxaa)maxaa=t1[i];
		if(t2[i]>=maxb)maxbb=maxb,maxb=t2[i];
		else if(t2[i]>maxbb)maxbb=t2[i];
	}
	if(maxa>maxb)
	{
		return 1;
	}
	else if(maxa==maxb)
	{
		if(maxaa>maxbb)return 1;
		else return 0;
	}
	return 0;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	LL T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		memset(w,0,sizeof w);
		memset(s,0,sizeof s);
		memset(x,0,sizeof x);
		for(LL i=1;i<=n;i++)
		{
			for(LL j=0;j<3;j++)
			{
				LL t;
				scanf("%lld",&t);
				w[i].push_back(t);
			}
		}
		
		sort(w+1,w+1+n,cmp1);
		
		for(LL i=1;i<=n;i++)
		{
			for(LL j=0;j<3;j++)
			{
				s[i].push_back({w[i][j],j});
			}
			sort(s[i].begin(),s[i].end());
			reverse(s[i].begin(),s[i].end());
			s[i].push_back({-1e9,3});
		}
		
		LL res=0;
		priority_queue<piii,vector<piii>,greater<piii>> q[4];
		for(LL i=1;i<=n;i++)
		{
			if(x[s[i][0].second]<n/2)
			{
				res+=s[i][0].first;
				piii tt={s[i][0].first-s[i][1].first,{i,0}};
				q[s[i][0].second].push(tt);
				x[s[i][0].second]++;
			}
			else
			{
				piii t=q[s[i][0].second].top();
				q[s[i][0].second].pop();
				
				if(s[t.second.first][t.second.second].first+s[i][1].first>=s[t.second.first][t.second.second+1].first+s[i][0].first)
				{
					res+=s[i][1].first;
					piii tt={s[i][1].first-s[i][2].first,{i,1}};
					q[s[i][1].second].push(tt);
					q[s[i][0].second].push(t);
					x[s[i][1].second]++;
				}
				else
				{
					res-=s[t.second.first][t.second.second].first;
					res+=s[t.second.first][t.second.second+1].first;
					res+=s[i][0].first;
					piii ttt={s[t.second.first][t.second.second+1].first-s[t.second.first][t.second.second+2].first,{i,t.second.second+1}};
					piii tt={s[i][0].first-s[i][1].first,{i,0}};
					q[s[i][0].second].push(tt);
					q[s[t.second.first][t.second.second+1].second].push(ttt);
					x[s[t.second.first][t.second.second+1].second]++;
				}
			}
		}
		
		printf("%lld\n",res);
	}
	
	return 0;
}
