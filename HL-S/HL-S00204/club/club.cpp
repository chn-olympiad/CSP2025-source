#include<bits/stdc++.h>
using namespace std;

int n,a[100005][4],f[35][20][20][20],T,h,b[100005];

struct B
{
	int x,y,c;
}d[100005];

void shuru()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i][1]>>a[i][2]>>a[i][3];
	h=n/2;	
}

bool checkA()
{
	for(int i=1;i<=n;i++)
	  if((a[i][2]!=0)||(a[i][3]!=0))
	    return 0;
	return 1;
}

bool checkB()
{
	for(int i=1;i<=n;i++)
	  if(a[i][3]!=0)
	    return 0;
	return 1; 
}

void solveA()
{
  for(int i=1;i<=n;i++)
    b[i]=a[i][1];
  sort(b+1,b+1+n);
  int ans=0;
  for(int i=n;i>h;i--)
  {
  	ans+=b[i];
  }
  cout<<ans<<"\n";
}

bool cmp(B e,B f)
{
	return e.c>f.c;
}

void solveB()
{
	for(int i=1;i<=n;i++)
	{
		d[i].x=a[i][1];
		d[i].y=a[i][2];;
		d[i].c=d[i].x-d[i].y;
	}
	sort(d+1,d+1+n,cmp);
	int ans=0;
	for(int i=1;i<=h;i++)
	  ans+=d[i].x;
	for(int i=h+1;i<=n;i++)
	  ans+=d[i].y;
	cout<<ans<<"\n";
}

void solve1()
{
	f[0][0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=h;j++)
		{
			for(int k=0;k<=h;k++)
			{
				for(int l=0;l<=h;l++)
				{
					f[i][j][k][l]=0;
					if(l>h)
					  continue;
					if(j>0)
					  f[i][j][k][l]=max(f[i-1][j-1][k][l]+a[i][1],f[i][j][k][l]);
					if(k>0)
					  f[i][j][k][l]=max(f[i-1][j][k-1][l]+a[i][2],f[i][j][k][l]);
					if(l>0)
					  f[i][j][k][l]=max(f[i-1][j][k][l-1]+a[i][3],f[i][j][k][l]);
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=h;i++)
	{
		for(int j=0;j<=h;j++)
		{
			int k=n-i-j;
			if(k>h)
			  continue;
			ans=max(ans,f[n][i][j][k]);
		}
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		shuru();
		if(checkA())
		  solveA();
		else if(checkB())
		  solveB();
		else
		  solve1();
	} 
	return 0;
} 
