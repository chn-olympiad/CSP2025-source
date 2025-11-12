#include<bits/stdc++.h>
using namespace std;
int t,n;
int q;
struct node
{
	int m,n,c,bb;
}a[100086];
int b[100086];
bool cmp(node a,node b)
{
	if(a.c<b.c)return 1;
	else return 0;
}
int main()
{
	int jsa=0,jsb=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int ans=0;
	for(int z=0;z<t;z++)
	{
		ans=0;
		cin>>n;
		jsa=n;jsb=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i].m>>a[i].n>>q;
			a[i].c=max(a[i].m,a[i].n)-min(a[i].m,a[i].n);
			a[i].bb=i;
			b[i]=a[i].m;
			if(a[i].n>a[i].m)
			{
				b[i]=a[i].n;
				jsa--;jsb++;
			}
		}
		sort(a,a+n,cmp);
		if(jsa>n/2||jsb>n/2)
		{
			for(int i=0;i<max(jsa,jsb)-(n/2);i++)
			{
				b[a[i].bb]=min(a[i].m,a[i].n);
			}
		}
		for(int i=0;i<n;i++)ans+=b[i];
		cout<<ans;
		if(z!=t-1)cout<<endl;
	}
	return 0;
}
