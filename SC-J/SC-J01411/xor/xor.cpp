#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l,r;
};
int n,k;
int a[500010];
int b[1010][1010];
node c[1000010];
bool cmp(node x,node y)
{
	return x.r<y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i][i]=a[i]; 
		if(b[i][i]==k)
		{
			cnt++;
			c[cnt].l=i;
			c[cnt].r=i;
		}
	}
	
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i+l-1<=n;i++)
		{
			int j=i+l-1;
			b[i][j]=a[j];
			b[i][j]^=b[i][j-1];
			if(b[i][j]==k)
			{
				cnt++;
				c[cnt].l=i;
				c[cnt].r=j;
			}
		}
	}
	sort(c+1,c+cnt+1,cmp);
	int num=0;
	int last=0;
	for(int i=1;i<=cnt;i++)
	{
		if(c[i].l>last)
		{
			last=c[i].r;
			num++;
		}
	}
	cout<<num;
	return 0;
}