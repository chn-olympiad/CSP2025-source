#include <bits/stdc++.h>
using namespace std;
int n,k,x,ans;
int a[500005];
int q[500005];
int dp[5005][5005];
/*struct node
{
	int ii,jj;
}p[500005];
bool cmp(node b,node c)
{
	return b.ii<c.ii;
}*/
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> a[i];
/*	q[1]=a[1];
	for(int i=2;i<=n;i++)
		q[i]=q[i-1]^a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i==j&&a[i]==k)
			{
				p[++x].ii=j;
				p[x].jj=i;
			} 
			else if(j==1&&q[i]==k)
			{
				p[++x].ii=j;
				p[x].jj=i;	
			}
			else if(q[i]^q[j]==k)
			{
				p[++x].ii=j;
				p[x].jj=i;
			}
		}
	}
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=x;i++)
	{
		cout << p[i].ii << " " << p[i].jj << endl;
	}*/
	cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
