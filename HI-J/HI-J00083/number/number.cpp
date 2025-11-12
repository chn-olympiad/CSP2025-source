#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int m;
	//ÊäÈë×Ö·û´® 
	cin>>s;
	cout<<s;
	/*
	int n=s.size()+5;
	long long a[n];
	a[0]=0;
	for(int i=0;i<=n;i++)
	{
		if('s[i]'>='0'&&'s[i]'<='9')
		{
			m=1;
			if(s[i]>=a[i-m])
			{
				a[i]=s[i];
			}
			else
			{
				while(s[i]>=a[i-m])
				{
					a[i-m+1]=a[i-m];
					s[i]=a[i-m];
					m++;
				}
			}
		}
    }
	cout<<a;
	*/
	
	return 0;
}
