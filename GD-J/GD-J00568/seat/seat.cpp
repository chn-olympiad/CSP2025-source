#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,s,w;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
    {
    	cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1);
	w=n*m;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[w]==s)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				w--;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(a[w]==s)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				w--;
			}
		}
	}
	

	return 0;
}

