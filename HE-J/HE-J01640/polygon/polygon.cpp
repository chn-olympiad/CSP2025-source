#include<bits/stdc++.h>
using namespace std;
long long a[5010],b,c,d,n;
int main()
{
	fropen("polygon.in","r",stdin);
	fropen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	   cin>>a[i];
	if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])
	{
		cout<<"1";
		return 0;
	}
	cout<<"0";
	return 0;
	fclose(stdin);
	fclose(stdout);
}
