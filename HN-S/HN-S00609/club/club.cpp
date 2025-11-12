#include <bits/stdc++.h>
using namespace std;

const int N=100010;

int ans;
int b[5];
int maxn;
int t,n,k;
int a[N][5];

void f(int x,int p)
{
	int ss;
	if(x==n)
	{
		cout<<endl<<x<<' '<<p<<' '<<ans<<' ';
		if(ans>maxn)
		{
			maxn=ans;
		}
		b[p]--;
	}
	else
	{
		for(int i=0;i<3;i++)
		{
			ss=i;
			cout<<endl<<x<<' '<<p<<' '<<ans<<' ';
			if(b[i]<k)
			{
				ans+=a[x][i];
				b[i]++;
				f(x+1,i);
				ans-=a[x][i];
				if(x==n-1 && i==2)
				{
					b[p]--;
					//f(x,p);
					//x--;
					//ans+=a[x][p];
					//ans-=a[x][i];
				}
			}
		}
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		k=n/2;
		ans=0;
		maxn=-1;
		b[0]=0,b[1]=0,b[2]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			f(i,0);
		}
		cout<<maxn<<endl;
	}
	return 0;
}
