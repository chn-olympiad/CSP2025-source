#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1000005],s,s1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			s1=i;
			break;
		}	
	}
	if(s1<=n)
	{
		cout<<1<<" "<<n;
		return 0;
	}
	else
	{
		if(s1%n!=0)
		{
			if((s1/n+1)%2==0)
			cout<<s1/n+1<<" "<<n-s1%n+1;
			else
			cout<<s1/n+1<<" "<<s1%n;
		}
		
		else
		{
			if(s1/n%2==0)
			{
				cout<<s1/n<<" "<<1;
				return 0;
			}
			else
			{
				cout<<s1/n<<" "<<n;
				return 0;
			}
		}
	}
	return 0;
}
