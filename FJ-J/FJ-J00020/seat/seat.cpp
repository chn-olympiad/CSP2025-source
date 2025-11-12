#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1; i<=n*m; i++)
	{
		cin>>a[i];
	}
	int q=a[1];
	sort(a+1,a+(n*m)+1);
	int s=0;
	for (int i=1; i<=n*m; i++)
	{
		if (a[i]==q)
		{
			s=i;
			break;
		}
	}
	q=n*m+1-s;
	int l=0,h=0;
	int ans=0;
	for (int i=1; i<=n; i++)
	{
		if (l!=0&&h!=0)
		{
			break;
		}
		if (i%2==0)
		{
			for (int j=m; j>=1; j--)
			{
				ans++;
				if (ans==q)
				{
					l=i;
					h=j;
					break;
				}
			}
		}else{
			for (int j=1; j<=m; j++)
			{
				ans++;
				if (ans==q)
				{
					l=i;
					h=j;
					break;
				}
			}
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
