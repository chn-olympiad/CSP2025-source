#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],k;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			if(i%n==0)
			{
				if((i/n)%2==0)
				{
					cout<<i/n<<" 1";
				}
				else
				{
					cout<<i/n<<" "<<n;
				}
			}
			else if(i%n!=0)
			{
				if(((i/n)+1)%2==0)
				{
					cout<<(i/n)+1<<" "<<n-(i%n)+1;
				}
				else
				{
					cout<<(i/n)+1<<" "<<i%n;
				} 
			}
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}  
