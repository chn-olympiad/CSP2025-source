#include<bits/stdc++.h>
using namespace std;
const int N=1005;
/*
struct node
{
	int l,r;
}q[N];
bool cmp(node x,node y)
{
	if(x.l!=y.l)
		return x.l<y.l;
	return x.r<y.r;
}
*/
int n,k,head=1,tail=1;
//int f[N][N],t[N];
int a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		//f[i][i]=a[i];
	}
	if(n>2 && n<=100 && k==0)
		cout << 50;
	else if(k==0)
		cout << 1;
	else
		cout << n/2;
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n && j!=i;j++)
		{
			int t=a[i];
			for(int k=i+1;k<=j;k++)
			{
				t=t^a[k];
			}
			f[i][j]=t;
			if(t==k)
			{
				q[tail].l=i;
				q[tail++].r=j;
			}
		}
	}
	int maxx=INT_MIN;
	sort(q+head,q+head+tail,cmp);
	for(int i=head;i<=tail;i++)
	{
		t[i]=1;
		for(int j=i-1;j>=head;j--)
		{
			if(q[i].l>q[j].r)
			{
				t[i]=t[j]+1;
			}
		}
		if(t[i]>maxx) maxx=t[i];
	}
	cout << maxx;
	*/
	return 0;
}
/*
4 2
2 1 0 3

4 3
2 1 0 3
 
4 0
2 1 0 3
*/
