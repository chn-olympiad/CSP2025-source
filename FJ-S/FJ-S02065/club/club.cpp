#include<iostream>
#include<cstdio>
using namespace std;
struct bu
{
	int a1,b1,c1;
}aa[100];
int main()
{
	freopen("club.in","r",stdin)
	freopen("club.out","w",stdout)
	int n;
	int m;
	int sum=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>aa[i].a1>>aa[i].b1>>aa[i].c1;
	
	}
	for(int i=0;i<m;i++)
	{
		int s=0;
		s=max(aa[i].a1,aa[i].b1);
		int y=0;
		y=max(aa[i].b1,aa[i].c1);
		int bb=0;
		bb=max(s,y);
		sum+=bb;
	}
	cout<<sum;
	return 0;
}
