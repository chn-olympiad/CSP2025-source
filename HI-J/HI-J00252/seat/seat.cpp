#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,meb;cin>>n>>m;meb=n*m;
	for(int i=1;i<=meb;i++) cin>>a[i];
	int R_score=a[1];
	sort(a+1,a+1+meb);
	for(int i=1;i<=m;i++)
	{
		if(i%2) for(int j=1;j<=n;j++,meb--)
		{
			if(a[meb]==R_score)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
		else for(int j=n;j>=1;j--,meb--)
		{
			if(a[meb]==R_score)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
