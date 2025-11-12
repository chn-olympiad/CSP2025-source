#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s1[200001],s2[200001],ss,ss2,a,a1;
bool sou(string x,string y)
{
	int lo=x.size(),lo2=y.size(),xx=0;
	for(int i=0;i<lo2;i++)
	{
		if(x[xx]==y[i])
		  xx++;
		else
		  xx=0;
		if(xx==lo)
		  return 1;
	}
	return 0;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>ss>>ss2;
		int lo=ss.size(),sum=0,x,y;
		for(int i=0;i<lo;i++)
		{
			if(ss[i]!=ss2[i])
			{
				x=i;
				break;
			}
		}
		for(int i=lo-1;i>=0;i--)
		{
			if(ss[i]!=ss2[i])
			{
				y=i;
				break;
			}
		}
		for(int i=x;i<=y;i++)
		{
			a+=ss[i];
			a1+=ss2[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(sou(a,s1[i])&&sou(a1,s2[i]))
			  sum++;
		}
		cout<<sum<<endl;
	}
    return 0;
}
