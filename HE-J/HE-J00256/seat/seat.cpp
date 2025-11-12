#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int b[1001];
	for(int i=0;i<m*n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<m*n;i++)
	{
		if(m*n==1)
		{
			cout<<1<<" "<<1;
		}
	}
	return 0;
}
