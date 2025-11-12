#include<iostream>
using namespace std;
int const maxn=100;
int main()
{
	char s;
	int size,big[maxn];
	cin>>s;
	size=sizeof(s);
	int si[maxn];
	for(int i=1;i<=size;i++)
	{
		si[i]=s;
	}
	for(int i=1;i<=size;i++)
	{
	
		for(int j=i+1;j<=size;j++)
		{
			if(si[i+1]>si[i-1])
			{
				big[i]=si[i];
			}
			cout<<big[i];
		}
		
	}
	return 0;
}
