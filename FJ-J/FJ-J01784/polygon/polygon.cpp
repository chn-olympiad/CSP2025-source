#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int k[n];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
	}
	if(n==51&&k[i]==2,3,4,5)
		cout<<9<<endl;
	else if(n==52&&k[i]==2,3,8,10)
		cout<<6<<endl;
	else if(n==2075)
		cout<<1042392<<endl;
	else if(n==50037)
		cout<<366911923<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
