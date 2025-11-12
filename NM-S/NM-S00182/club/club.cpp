#include<bits/stdc++.h>
using namespace std;
struct Men
{
	int a;
	int b;
	int c;
	int fun;
	int next;
	int last;
	map<int,int> lop;
};
int allmax(int d,int f,int e)
{
	int ans=max(d,f);
	ans=max(ans,e);
	return ans;
}
int allmin(int d,int f,int e)
{
	int ans=min(d,f);
	ans=min(ans,e);
	return ans;
}
int middle(int d,int f,int e)
{
	int as=max(d,f);
	int df=min(e,f);
	if(as==f&&df==f)
	{
		return f;
	}
	if(as==d&&df==e)
	{
		return f;
	}
	if(as==d&&df==f)
	{
		return min(e,d);
	}
	if(as==f&&df==e)
	{
		return max(e,d);
	}
	return 0;
}
bool som(Men a,Men b)
{
	return a.fun>b.fun;
}
int pdf()
{
	int n;
	cin>>n;
	Men m[100005];
	for(int i=0;i<n;i++)
	{
		cin>>m[i].a>>m[i].b>>m[i].c;
		m[i].lop[m[i].a]=0;
		m[i].lop[m[i].b]=1;
		m[i].lop[m[i].c]=2;
		m[i].fun=allmax(m[i].a,m[i].b,m[i].c);
		m[i].next=middle(m[i].a,m[i].b,m[i].c);
		m[i].last=allmin(m[i].a,m[i].b,m[i].c);
		
	}
	sort(m,m+n,som);
	int j[3]={0,0,0};
	int ans[3]={0,0,0};
	
	queue<Men> q;

	for(int i=0;i<n;i++)
	{
		q.push(m[i]);
	}
	Men k[3];
	int v[3]={1,1,1};
	while(!q.empty())
	{
		Men k1=q.front();
		q.pop();
		if(j[k1.lop[k1.fun]]<=(n/2)-1)
		{
			j[k1.lop[k1.fun]]++;
			ans[k1.lop[k1.fun]]+=k1.fun;
			if(k1.fun<k[k1.lop[k1.fun]].fun||v[k1.lop[k1.fun]]==1)
			{
				k[k1.lop[k1.fun]]=k1;
				v[k1.lop[k1.fun]]=0;
			}
		}
		else{
			k1.fun=k1.next;
			k1.next=k1.last;
			
			q.push(k1);
			
		}
		if(j[k1.lop[k1.fun]]>=n/2)
		{
			if(k[k1.lop[k1.fun]].next>k1.fun)
			{
				ans[k1.lop[k1.fun]]-=k[k1.lop[k1.fun]].fun;
				ans[k1.lop[k1.fun]]+=k1.fun;
				k[k1.lop[k1.fun]].fun=k[k1.lop[k1.fun]].next;
				k[k1.lop[k1.fun]].next=k[k1.lop[k1.fun]].last;
				q.push(k[k1.lop[k1.fun]]);
				k[k1.lop[k1.fun]]=k1;
			}
		}
	}
	return ans[0]+ans[1]+ans[2];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int number;
	cin>>number;
	for(int i=0;i<number;i++)
	{
		cout<<pdf()<<endl;
	}
	return 0;
}
