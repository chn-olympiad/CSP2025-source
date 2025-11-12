#include<bits/stdc++.h>
using namespace std;
long long n,k,s=0;
bool b=0;
pair<int,int> p[1000005];
void f(int l,int r)
{
	if(l>=r){return ;}
	bool flag=0;
	for(int i=l;i<=r;i++)
	{
		if(p[i].second!=0)
		{
			flag=1;
			break;
		}
	}
	if(!flag){return ;}
	for(int i=l;i<=r;i++)
	{
		if(p[i].first==k)
		{
			s++;
			p[i].first=p[i].second=0;
			for(int j=r;j>=l;j--)
			{
				if(j==i){continue;}
				p[j].second=p[j+1].first; 
				p[j].first=p[j].first^p[j].second;
			}
			f(l,i-1);
			f(i+1,r);
			break;
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>p[i].first;
		if(i>0)
		{
			p[i-1].second=p[i].first;
		}
		if(p[i].first!=1&&p[i].first!=0){b=1;}
	}
	if(!b)
	{
		if(k==1)
		{
			for(int i=0;i<n;i++)
			{
				if(p[i].first==1)
				{
					s++;
				} 
			} 
			cout<<s;
		}
		if(k==0)
		{
			for(int i=0;i<n;i++)
			{
				if(p[i].first==0)
				{
					s++;
				}
				if(p[i].first==1&&p[i+1].first==1)
				{
					s++;
					i++;
				}
			} 
			cout<<s;
		}
	}
	else
	{
		f(0,n-1);
		cout<<s;
	}
	return 0;
}