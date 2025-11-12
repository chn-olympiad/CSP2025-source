#include<bits/stdc++.h>
using namespace std;
string a;
int z[20],y,x=1;
int main()
{
	peropen("number.in","r",stdin);
	peropen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='a'&&a[i]<='z'&&a[i]>='A'&&a[i]<='Z');
		else
		{	if(a[i]=='0') z[0]++;
			else if(a[i]=='1') z[1]++;
			else if(a[i]=='2') z[2]++;
			else if(a[i]=='3') z[3]++;
			else if(a[i]=='4') z[4]++;
			else if(a[i]=='5') z[5]++;
			else if(a[i]=='6') z[6]++;
			else if(a[i]=='7') z[7]++;
			else if(a[i]=='8') z[8]++;
			else if(a[i]=='9') z[9]++;
		}
	}
	for(int i=0;i<=9;i++)
	{
		if(z[i]>=1)
		{
			while(z[i]--)
			{
				cout<<i<<endl;
				y=y+i*x;
				x=x*10;
			}
		}
	}
	cout<<y<<endl;
	return 0;
}
