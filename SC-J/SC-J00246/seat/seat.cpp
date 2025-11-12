#include<bits/stdc++.h>
using namespace std;
int a[101],b[101],w;	
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	b[a[1]]=1;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(b[a[i]]==1)
		{
			w=n*m-i+1;
			break;
		}
	}
	if(((w-1)/n)%2==0)
	{
		cout<<(w-1)/n+1<<" "<<(w-1)%n+1;
	}
	else
	{
		cout<<(w-1)/n+1<<" "<<n-(w-1)%n;
	}
	return 0;
}