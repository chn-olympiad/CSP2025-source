#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l,r;
}a[500111];
int s[500111];
bool e[500111];
int count(int s[],int l,int r)
{
	int ans=s[l];
	for(int i=l+1;i<=r;i++)
	{
		ans=ans^s[i];
	}
	return ans;
}
bool comp(node a,node b)
{
	return a.r<b.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,m=1,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			if(count(s,l,r)==k)
			{
				a[m].l=l;
				a[m].r=r;
				m++;
			}
		}
	}
	sort(a+1,a+1+m,comp);
	for(int i=1;i<=m;i++)
	{
		if(!e[i]) 
		{
			for(int j=i+1;;j++)
			{
				if(a[j].l>a[i].r||j==m+1) break;
				e[j]=1;
			}
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

