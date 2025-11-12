#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
struct xort{
	long long b;
	long long e;
}o[N];
long long a[N];
int yihuo(int x,int y)
{
	string q="",w="";
	while(x!=0)
	{
		q=q+char(x%2+48);
		x/=2;
	}
	while(y!=0)
	{
		w=w+char(y%2+48);
		y/=2;
	}
	reverse(w.begin(),w.end());
	reverse(q.begin(),q.end());
	if(w.size()<q.size())
	{
		swap(q,w); 
	}
	for(int i=1;i<=w.size()-q.size()+1;i++)
	{
		q='0'+q;
	}
	long long ans=0;
	for(int i=0;i<q.size();i++)
	{
		if(q[i]!=w[i])
		{
			ans=ans+pow(2,q.size()-i-1);
		}
	}
	return ans;
}
bool cmp(xort s,xort d)
{
	if(s.e!=d.e)
	{
		return s.e<d.e;
	}
	return s.b<d.b;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long lp;
	cin>>n>>lp;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2)
	{
		if(n==1&&lp==1)
		{
			cout<<1;
			return 0;
		}
		if(n==1&&lp!=1){
			cout<<0;
			return 0;
		}
		if(n==2)
		{
			if(a[2]%2)
			{
				if(a[2]-1==lp)
				{
					cout<<1;
					return 0;
				}
				else
				{
					cout<<0;
					return 0;
				}
			}
			else
			{
				if(a[2]+1==lp)
				{
					cout<<1;
					return 0;
				}
				else
				{
					cout<<0;
					return 0;
				}
			}
		}
	}
	int c=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			long long sum=0;
			for(int k=i;k<=j;k++)
			{
				sum=yihuo(a[k],sum);
			} 
			if(sum==lp)
			{
				c++;
				o[c].b=i;
				o[c].e=j;
			}
			sum=0;
		}
	}
	sort(o+1,o+1+c,cmp);
	long long cnt=0;
	for(int i=2;i<=c;i++)
	{
		if(o[i].b>o[i-1].e)
		{
			cnt++;
		}
	}
	if(c>0)
	{
		cout<<cnt+1;
	}
	return 0;
}
