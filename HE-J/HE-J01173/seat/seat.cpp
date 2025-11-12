#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m]; 
	cin>>a[0];
	int x=a[0];
	for(int i=1;i<n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n*m-1;i++)
	{
		for(int j=0;j<n*m-i-1;j++)
		{
			if(a[j]<a[j+1])swap(a[j],a[j+1]);
		}
	}
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==x){
			if((i+1)%n==0)cout<<(i+1)/n<<" "<<m;
			else 
			{
				int c=(i+1)/n;
			    if((c+1)%2==1)cout<<(i+1)/n+1<<" "<<(i+1)%n;
			    else cout<<(i+1)/n+1<<" "<<m-i%n;
			}
		}
	}
	return 0;
}
