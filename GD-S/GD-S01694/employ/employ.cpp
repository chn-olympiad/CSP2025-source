#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[555];
int jc(int a)
{
	int sum=1;
	for(int i=1;i<=a;i++)sum*=i;
	return sum;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string a;
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)cin>>c[i];
	int s=a.size();
	bool stjz=0;
	int js=0;
	for(int i=0;i<s;i++)
	{
		if(a[i]=='0')stjz=1,js++;
	}
	if(!stjz)
	{
		cout<<jc(n);
		return 0;
	}
	if(js>(n-m))
	{
		cout<<0;
		return 0;
	}
	return 0;
}
//可以获得免费的20分吗 
