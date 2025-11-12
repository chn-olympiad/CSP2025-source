#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
char a[N];
int n[11],k;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]<=57&&a[i]>=48)
		{
			n[a[i]-48]+=1;
		}
		
	}
	for(int i=9;i>=0;i--)
	{
		if(n[i]!=0)
		{
			for(int j=1;j<=n[i];j++)
			{
				cout<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
