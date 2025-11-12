#include<bits/stdc++.h>
using namespace std;
string a;
long long b[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long c=a.size();
	for(long long i=0;i<c;i++)
	{
		int f=a[i]-'0';
		if(f>=0&&f<10)
		{
			b[f]+=1;
		}
	}
	for(int i=10;i>=0;i--)
	{
		if(b[i]!=0)
		{
			for(int j=1;j<=b[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
