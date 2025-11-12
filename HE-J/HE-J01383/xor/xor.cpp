#include<bits/stdc++.h>
using namespace std;
int n=0,a[5000001]={0},l=0,r=0,k=0,t=0,s=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	l=1;
	while(l<=n)
	{
		s=0;
		for(r=l;r<=n;r++)
		{
			s^=a[r];
			if(s==k)
			{
				t++;
				l=r+1;
				break;
			}
		}
	}
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
