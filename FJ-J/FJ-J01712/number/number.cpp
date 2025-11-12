#include <iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[1000005],b[1005];
	cin>>s;
	int j=1;
	for (int i=0;i<s.length();i++)
	{
		a[i+1]=s[i];
		
		if (a[i+1] == '0' || a[i+1] == '1' || a[i+1] == '2' || a[i+1] == '3' || a[i+1] == '4' || a[i+1] == '5' || a[i+1] == '6' || a[i+1] == '7' || a[i+1] == '8' || a[i+1] == '9')
		{
			s[j]=a[i+1];
			j++;
		}
	}
	for (int i=1;i<=j-2;i++)
	{
		for (int k=1;k<=j-1-i;k++)
		{
			if (s[k]<s[k+1]) 
			{
				char l=s[k];
				s[k]=s[k+1];
				s[k+1]=l;
			}
				
		}
	}
	for (int i=1;i<=j-1;i++)
		cout<<s[i];
	return 0;
 } 
