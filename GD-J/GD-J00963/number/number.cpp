#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string c;
int a[1005],cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	for(int i=0;i<=c.size();i++)
	{
		if(c[i]>=48&&c[i]<=57)
		{
			cnt++;
			a[cnt]=c[i]-48;
		}
	}
	for(int i=1;i<=cnt;i++)for(int j=i+1;j<=cnt;j++)if(a[j]<a[i])swap(a[i],a[j]);
    for(int i=cnt;i>=1;i--)cout<<a[i];
	return 0;
}
