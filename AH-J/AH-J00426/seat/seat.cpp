#include<bits/stdc++.h>
using namespace std;
int m,n,a1;
int a[110];
bool cmp(int x,int y)
{
	return x>y;
	}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		}
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==a1)
		{
			if(((i-1)/n+1)%2==0)cout<<(i-1)/n+1<<" "<<((i-1)/n+1)*m-i+1;
			else cout<<(i-1)/n+1<<" "<<i-((i-1)/n)*m;
			return 0; 
			}
		}
	}
