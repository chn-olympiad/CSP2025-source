#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int ar[1000010]={0},i=1,x;
	int l=0;
	long long n;
	cin>>n;
	while(n>0)
	{
		ar[i]=n%10;
		n/=10;
		i+=1;
		l+=1;
	}
	for(int j=1;j<=l;j++)
	{
		for(int i=1;i<l;i++)
		{
			if(ar[i]<ar[i+1])
			{
				x=ar[i];
				ar[i]=ar[i+1];
				ar[i+1]=x;
			}
		}
	}
	for(int i=1;i<=l;i++)
	{
		cout<<ar[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
