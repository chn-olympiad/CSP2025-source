#include<bits/stdc++.h>
#define piii pair<int,pair<int,int>>
using namespace std;
long long a,b,c,st[20001],si[20001],bs[21],out,len,l,r,v,d;
priority_queue<piii,vector<piii>,greater<piii>>es;

struct edge
{
	int l,r,v;
}as[2000001],ds[20001];

struct city
{
	int to,v;
}cs[21][20001];

int cmp1(edge a,edge b)
{
	return a.v<b.v; 
}

int cmp2(city a,city b)
{
	return a.v<b.v;
}

void clear()
{
	for(int i=1;i<=a+c;i++)
	{
		st[i]=i;
		si[i]=1;
	}
}

int find(int p)
{
	if(st[p]==p)return p;
	return st[p]=find(st[p]);
}

int same(int p,int q)
{
	return find(p)==find(q);
}

int unio(int p,int q)
{
	p=find(p);q=find(q);
	if(p==q)return 0;
	if(si[p]<si[q])swap(p,q);
	st[q]=p;
	si[p]+=si[q];
	return 1;
}

piii mp(int l,int r,int v)
{
	return make_pair(v,make_pair(l,r));
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c;clear();
	for(int i=1;i<=b;i++)
	{
		cin>>as[i].l>>as[i].r>>as[i].v;
	}
	sort(as+1,as+b+1,cmp1);
	for(int i=1;i<=c;i++)
	{
		cin>>bs[i];
		for(int j=1;j<=a;j++)
		{
			cin>>cs[i][j].v;
			cs[i][j].to=j;
		}
		sort(cs[i]+1,cs[i]+a+1,cmp2);
	}
	for(int i=1;i<=b;i++)
	{
		if(unio(as[i].l,as[i].r))
		{
			out+=as[i].v;
			ds[++len]=as[i];
		}
	}
	for(int i=1;i<1<<c;i++)
	{
		for(;es.size();es.pop());clear();d=0;
		for(int j=1;j<=c;j++)
		{
			if((1<<(j-1))&i)
			{
				d+=bs[j];
				es.push(mp(j,1,cs[j][1].v));
			}
		}
		for(int j=1;j<a;j++)
		{
			if(es.size()&&es.top().first<ds[j].v)
			{
				l=es.top().second.first;
				r=es.top().second.second;
				v=es.top().first;es.pop();
				if(r<a)es.push(mp(l,r+1,cs[l][r+1].v));
				r=cs[l][r].to;l+=a;j--;
			}
			else
			{
				l=ds[j].l;r=ds[j].r;v=ds[j].v;
			}
			d+=unio(l,r)*v;
			if(d>=out)break;
		}
		out=min(out,d);
	}
	cout<<out;
	return 0;
}
