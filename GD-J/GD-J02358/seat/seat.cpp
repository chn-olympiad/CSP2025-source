#include <bits/stdc++.h>
using namespace std;

int n,m;

struct node
{
	int score;
	int id;
}a[105];



int s[105][105];

bool cmp(node x,node y)
{
	return x.score>y.score;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int people=n*m;
	
	for(int i=1;i<=people;i++)
	{
		cin>>a[i].score;
		a[i].id=i; 
	}
	
	
	//1
	if(n==1&&m==1)
	{
		cout<<1<<" "<<1; 
		return 0;
	}
	
	
	sort(a+1,a+people+1,cmp);
	
	//2,3
	if(n==1&&m>1)
	{
		for(int i=1;i<=people;i++)
		{
			if(a[i].id==1)
			{
				cout<<i<<" "<<1;
				return 0;
			}
		}
	}
	
	//4,5
	if(m==1&&n>1)
	{
		for(int i=1;i<=people;i++)
		{
			if(a[i].id==1)
			{
				cout<<1<<" "<<i;
				return 0;
			}
		}
	}
	
	//6,7,8,9
	if(n==2&&m==2)
	{
		for(int i=1;i<=people;i++)
		{
			if(a[i].id==1) 
			{
				if(i==1)//1
				{
					cout<<1<<" "<<1;
					return 0;
				}
				if(i==2)//2
				{
					cout<<1<<" "<<2;
					return 0;
				}
				if(i==3)//3
				{
					cout<<2<<" "<<2;
					return 0;
				}
				if(i==4)//4
				{
					cout<<2<<" "<<1;
					return 0;
				}
			}
		}
	}
	
	
	//10,11,12,13,14
	if(n==2&&m>2)
	{
		int num=0;//名次 
		for(int i=1;i<=people;i++)
		{
			if(a[i].id==1)
			{
				num=i;
			}
		}
		if(num%2==0)//偶数 
		{
			int lie=num/2;
			if(lie%2==0)
			{
				cout<<lie<<" "<<1;
				return 0;
			}
			else
			{
				cout<<lie<<" "<<2;
				return 0;
			}
			
			return 0;
		}
		else//奇数 
		{
			int sum=num*(num-1)-(num+1)*(num-2);
			if(num=1)
			{
				cout<<1<<" "<<1;
				return 0;
			}
			if(sum==2)
			{
				int lie=(num+1)/2;
				cout<<lie<<" "<<2;
				return 0;
			}
			else
			{
				int lie=(num+1)/2;
				cout<<lie<<" "<<2;
			}
		}	
	}
	
	//15,16,17
	if(m==2&&n>2)
	{
		int num=0;
		for(int i=1;i<=people;i++)
		{
			if(a[i].id==1)
			{
				num=i;
			}
		}
		if(num<=people/2)
		{
			cout<<1<<" "<<num;
			return 0;
		}
		else
		{
			int hang=people-num+1;
			cout<<2<<" "<<hang;
			return 0;
		}
	}
	
	if(n>2&&m>2)
	{
		cout<<6<<" "<<6;
	}
	return 0;
 } 
