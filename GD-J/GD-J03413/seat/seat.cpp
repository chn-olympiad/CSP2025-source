#include <bits/stdc++.h>
using namespace std;
int a[105],n,m,mark;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	mark=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=m;i++)
	{
		if (i%2==0){
			if (mark<=a[(i-1)*n+1] && mark>=a[i*n])
			{
				for (int j=(i-1)*n+1;j<=i*n;j++)
				{
					if (a[j]==mark)
					{
						cout<<i<<" "<<n-j+(i-1)*n+1;
						break;
					}
				}
			}	
		}
		else{
			if (mark<=a[(i-1)*n+1] && mark>=a[i*n])
			{
				for (int j=(i-1)*n+1;j<=i*n;j++)
				{
					if (a[j]==mark)
					{
						cout<<i<<" "<<j-(i-1)*n;
						break;
					}
				}
			}			
		}

	}
	return 0;
}
