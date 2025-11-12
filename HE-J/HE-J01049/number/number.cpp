#include<bits/stdc++.h>
using namespace std;
int a[1000008],jay,len;
string ak;
bool amd(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>ak;
    len=ak.size();
    if(len==1)
    {
    	cout<<ak;
	}
	else
	{
		for(int i=0;i<=len;i++)
		{
			int g=ak[i]-'0';
			if(g>=0&&g<=9)
			{
				a[jay]=g;
				jay++;
			}
		}
		sort(a,a+jay,amd);
		for(int i=0;i<jay;i++)
		{
			printf("%d",a[i]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
