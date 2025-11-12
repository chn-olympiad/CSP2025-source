#include<bits/stdc++.h>
using namespace std;
int n,m,R,k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m],e[n*m];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	R=a[0];
	k=n*m;
	sort(a,a+k);
	for(int i=k;i>0;i--)
	{
		for(int j=0;j<k;j++)
		{
			e[j]=a[i];
			if(e[j]==R && (j/m+1)%2==1)
			{
				cout<<j/m+1<<" "<<j%n+1;
				break;
			}
			else if(e[j]==R && (j/m+1)%2==0)
			{
				cout<<j/m+1<<" "<<4;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
