#include<bits/stdc++.h>
using namespace std;
struct aaa
{
	int x;
	int y;
}a[100005];
int main()
{
	for(int i=1;i<=3;i++)
	{
		cin>>a[i].x;
	}
	sort(a+1,a+ 4);
	for(int i=1;i<=3;i++)
	{
		cout<<a[i].x<<endl;
	}
	return 0;
}
