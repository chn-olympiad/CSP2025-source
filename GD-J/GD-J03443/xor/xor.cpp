#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],cc,js,last;
struct node
{
	int l,r;
}x[500005];
bool cmp(node shu1,node shu2)
{
	return shu1.r<shu2.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	s[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			last=i;
			x[++cc].l=i;
			x[cc].r=i;
			continue;
		}
		for(int j=i-1;j>=last+1;j--)
		{
			if((s[i]^s[j-1])==k)
			{
				last=i;
				x[++cc].l=j;
				x[cc].r=i;
				break;
			}
		}
	}
	last=-1;
	sort(x+1,x+1+cc,cmp);
	for(int i=1;i<=cc;i++)
	{
		if(x[i].l>last)
		{
			last=x[i].r;
			js++;
		}
	}
	cout<<js;
	
	return 0;
}
