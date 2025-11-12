#include<bits/stdc++.h>
#include<string>
using namespace std;
int n,k,a[500010],s1[500010];
std::string l[500010],skl;
int sor(int l1,int r)
{
	if(l1==r) return a[l1];
	int t=0;
	for(int i=l1;i<r;i++)
	{
		int p=l[i].size();
		int oi=l[i+1].size();
		int s=min(p,oi),a=max(p,oi);
		if(a==p) skl=l[i];
		else skl=l[i+1];
		for(int j=s-1;j>=0;j--)
		{
			if(l[i][j]==0 or l[i+1][j]==0)
			{
				skl[j]='1';
			}
			else
			{
				skl[j]='0';
			}
		}
		int c=0,d=1;
		for(int j=0;j<a;j++)
		{
			c+=(skl[j]-'0')*d;
			d*=2;
		}
		t+=c;
	}
	return t;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
		string c="";
		int t=a[i];
		while(t)
		{
			c+=t%2+'0';
			t/=2;
		}
		reverse(c.begin(),c.end());
		l[i]=c;
	}
	int l=1,r=1,z=0,cs=0,q=1,maxn=0;
	while(r<=n)
	{
		z=sor(l,r);
		if(z==k)
		{
			cs++;
			l=r+1;
			r=l;
		}
		r++;
	}
	cout<<cs;
    return 0;
}
