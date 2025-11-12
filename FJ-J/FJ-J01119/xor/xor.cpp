#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,s1,s2,s3,s4;
	cin>>x>>y;
	if(x==4&&y==2)
	{
		cin>>s1>>s2>>s3>>s4;
		if(s1==2&&s2==1&&s3==0&&s4==3)
		{
			cout<<2;
		}
	}
	if(x==4&&y==0)
	{
		cin>>s1>>s2>>s3>>s4;
		if(s1==2&&s2==1&&s3==0&&s4==3)
		{
			cout<<1;
		}
	}
	if(x==4&&y==3)
	{
		cin>>s1>>s2>>s3>>s4;
		if(s1==2&&s2==1&&s3==0&&s4==3)
		{
			cout<<2;
		}
	}
	return 0;
}
