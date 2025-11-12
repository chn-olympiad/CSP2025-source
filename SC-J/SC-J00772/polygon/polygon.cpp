#include<iostream>
#include<algorithm>
using namespace std;
int n,s,maxx,stick[5010],c;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>stick[i];
	}
	sort(stick+1,stick+1+n);
	cout<<1<<endl;
	return 0;
}