#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	int s;
	int q;
	int n=0;
	cin>>s;
	int a[100011];
	while(s>0)
	{
		a[n]=s%10;
		s/=10;
		n++;
	}
	for(int y=0;y<n;y++)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]<a[i+1])
			{
				q=a[i];
				a[i]=a[i+1];
				a[i+1]=q;
			}
		}
	}

	for(int i=0;i<n;i++) cout<<a[i];
	
	return 0;
}
