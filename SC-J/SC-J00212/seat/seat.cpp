#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m; cin >>n >>m;
	for(int i=1;i<=n*m;i++) cin >>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1);
	int idx=n*m+1;
	for(int i=1;i<=m;i++) 
	{
		if(i%2==1) 
		{
			for(int j=1;j<=n;j++) 
			{
				idx--;
				if(a[idx]==x) return cout <<i <<' ' <<j,0;
			}
		}
		else 
		{
			for(int j=n;j>0;j--)
			{
				idx--;
				if(a[idx]==x) return cout <<i <<' ' <<j,0;
			}
		}
	}
	return 0;
}