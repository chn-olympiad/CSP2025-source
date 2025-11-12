#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n],sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		cin>>a[i];
	}
	int b=max(a[0],max(a[1],a[2]));
	if((b*2)<sum)
		cout<<"1";
	else
		cout<<"0";
	return 0;
}
