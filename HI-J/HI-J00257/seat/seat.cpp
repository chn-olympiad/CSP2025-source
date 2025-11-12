#include<bits/stdc++.h> 
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,c,r,r_sco;
	cin>>n>>m;
	int score[110];
	cin>>r_sco;
	score[1]=r_sco;
	for(int i=2;i<=n*m;i++)
	{
		cin>>score[i];
	}
	sort(score+1,score+m*n+1,cmp);
	int pos;
	for(int i=1;i<=n*m;i++)
	{
		if(score[i]==r_sco)
		{
			pos=i;
			break;
		}
	}
	if(pos%n==0)
	{
		c=pos/n;
		if(c%2==0)
		{
			r=1;
		}
		else
		{
			r=n;
		}
	}
	else
	{
		c=(pos/n)+1;
		if(c%2==0)
		{
			r=n-(pos%n)+1;
		}
		else
		{
			r=pos%n;
		}
	}
	cout<<c<<' '<<r;
	return 0; 
} 
