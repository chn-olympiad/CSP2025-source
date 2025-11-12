#include<iostream>
#include<string>
using namespace std;
int b[1000000],maxx=-1,n=0,mnum;;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(int(a[i])>=48 && int(a[i])<=57)
		{
			b[n]=int(a[i]-48);
			n++;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		int max=-1;
		for(int j=i;j<n;j++)
		{
			if(b[j]>max)
			{
				max=b[j];
				swap(b[i],b[j]);
			}
		}
		cout<<max;
	}
	return 0;
} 
