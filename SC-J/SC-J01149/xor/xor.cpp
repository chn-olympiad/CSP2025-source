#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int record[500005];
struct node
{
	int l,r;
}qujian[500005];
int num=0;
bool cmp(node a,node b)
{
	if(a.r<b.r)
	    return 1;
	else if(a.r==b.r && a.l>b.l)
	    return 1;
	return 0;
}
int main ()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		record[i]=(record[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if((record[i]^record[j-1])==k)
			    qujian[++num]={j,i};
		}
	}
	sort(qujian+1,qujian+1+num,cmp);
	int last=0;
	for(int i=1;i<=num;i++)
	{
		if(qujian[i].l>last)
		{
			ans++;
			last=qujian[i].r;
		}
	}
	cout<<ans;
    return 0;
}