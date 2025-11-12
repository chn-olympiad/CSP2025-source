#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int a,b[1000001],ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
		cin>>b[i];
	for(int i=1;i<=a;i++)
			if(b[i+1]>=b[i]*2)
				ans++;
	cout<<ans;
	return 0;
}
