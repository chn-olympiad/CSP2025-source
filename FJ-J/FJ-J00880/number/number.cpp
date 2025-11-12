#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char b;
	long a[100]={0};
	while(cin>>b)
	{
		if(b=='9')a[9]++;
		if(b=='8')a[8]++;
		if(b=='7')a[7]++;
		if(b=='6')a[6]++;
		if(b=='5')a[5]++;
		if(b=='4')a[4]++;
		if(b=='3')a[3]++;
		if(b=='2')a[2]++;
		if(b=='1')a[1]++;
		if(b=='0')a[0]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=a[i];j>0;j--)
		{
			cout<<i;
		}
	}
	return 0;
}
