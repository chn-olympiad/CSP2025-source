#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int b[499999];
	int l=0;
	string c;
	cin>>c;
	for(int i=1;i <= c.length();i++){
		if(c[i-1]=='1' or c[i-1]=='2' or c[i-1]=='3' or c[i-1]=='4' or c[i-1]=='5' or c[i-1]=='6' or c[i-1]=='7' or c[i-1]=='8' or c[i-1]=='9' or c[i-1]=='0')
		{
			l++;
			b[l]=c[i-1]-'0';
		}
	}
	for(int i=1;i<=l;i++)
	{
		for(int j=i+1;j<=l;j++)
		{
			if(b[j]>b[i])
			{
				swap(b[i],b[j]);
			}
		}
	}
	for(int i=1;i<=l;i++)
	{
		cout<<b[i];
	}
	return 0;
} 