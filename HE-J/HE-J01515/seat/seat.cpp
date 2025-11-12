#include<bits/stdc++.h>
using namespace std;
int a[105],n,m;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int b=a[1];
	sort(a+1,a+1+n*m,cmp); 
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			int k=i; 
			if(k<=n)
			{
				cout<<1<<" "<<k;
			}
			else if(k%n==0)
			{
				cout<<k/n<<" ";
				int c=k/n; 
				if(c%2==0)
				{
					cout<<1;
				}
				else if(c%2==1)
				{
					cout<<4;
				}
			}
			else if(k%n!=0)
			{
				cout<<k/n+1<<" ";
				int c=(k/n)+1;
				if(c%2==0)
				{
					cout<<m-(k%n)+1;
				} 
				else if(c%2!=0)
				{
					cout<<k%n; 
				}
			}
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
