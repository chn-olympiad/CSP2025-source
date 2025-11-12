#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int t[10]={0};
	int a=n.size();
	for(int i=1;i<=a;i++)
	{
		if(n[i]=='0')t[0]++;
		if(n[i]=='1')t[1]++;
		if(n[i]=='2')t[2]++;
		if(n[i]=='3')t[3]++;
		if(n[i]=='4')t[4]++;
		if(n[i]=='5')t[5]++;
		if(n[i]=='6')t[6]++;
		if(n[i]=='7')t[7]++;
		if(n[i]=='8')t[8]++;
		if(n[i]=='9')t[9]++;
	}
	for(int i=9;i>=0;i--)
	{
		if(t[i]>=1)
		{
			for(int j=1;j<=t[i];j++)
			{
				cout<<i;
			}
		}
	}
	 return 0;
}
