#include<bits/stdc++.h>
using namespace std;
long long c[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(long long i=0;i<a.size();i++)
	{
		c[a[i]-'0']++;
	}
	for(long long i=9;i>=0;i--)
	{
		for(long long j=1;j<=c[i];j++)
		{
			cout<<i;
		}
	}
	//CCF are sb!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//fuck ccf's mother£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡
	//ccf don't have 78 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
