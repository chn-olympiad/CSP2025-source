#include<bits/stdc++.h>
using namespace std;
int n,re=0,k;
string s;
char a[1000005],b[1000005];
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number3.out","w",stdout);
	cin>>s;
	int sd=s.size();
	for (int i=0;i<=sd;i++)
    {
        a[i+1]=s[i];
        if ( 48 <= int(a[i+1]) and int(a[i+1]) <= 57)
        {
            n++;
            b[n]=a[i+1];
        }
    }
    
    
    
    
    
    for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if(b[j]>re)
			{
				re=b[j];
				k=j;
			}	
		}
		a[i]=re;
		re=0;
		b[k]=0;
	}
		for (int i=1;i<=n;i++)
	{
		cout<<a[i];
	}
	return 0;
}
