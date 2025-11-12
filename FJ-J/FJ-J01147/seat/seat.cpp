#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,t,f,s;
struct chengji
{
	int num,i;
}b[100501],a[155][155];
bool cmp(chengji x,chengji y)
{
	return x.num>y.num;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1; i<=k; i++)
	{
		cin>>b[i].num;
		b[i].i=i;
	}
	sort(b+1,b+1+k,cmp);
	int j=1,f=1;
	while(f<=k)
	{
		for(int i=1; i<=m; i++)
		{
			if(j==0)
			{
				t=0;
				j=1;
			}
			else
				if(j==n+1)
				{
					t=1;
					j=n;
				}
			while(j>=1&&j<=n)
			{
				a[j][i].num=b[f].num;
				a[j][i].i=b[f].i;
				f++;
				if(t==0)
					j++;
				else
					j--;
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
			if(a[i][j].i==1)
			{
				cout<<j<<" "<<i;
				return 0;
			}
	}
	return 0;
}
