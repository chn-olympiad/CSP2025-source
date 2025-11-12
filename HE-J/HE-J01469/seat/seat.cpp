#include<bits/stdc++.h>
using namespace std;
int m,n;
int ls[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	int lens = m*n;
	for(int i = 0;i<m*n;i++)
	{
		cin>>ls[i];
	}
	int me = ls[0];
	int more = 1;
	for(int i = 0;i<lens;i++)
	{
		if(ls[i]>me)
		{
			more++;
		}
	}
	int a = 1+((more-1)/n);
	cout<<a<<" ";
	int b = more-(a-1)*n;
	if(a%2 == 1)
	{
		cout<<b;
	}
	else
	{
		cout<<n-b;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
