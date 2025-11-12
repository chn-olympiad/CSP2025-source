#include<bits/stdc++.h>
using namespace std;
string a;
long long ans[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='0')	ans[0]++;
		if(a[i]=='1')	ans[1]++;
		if(a[i]=='2')	ans[2]++;
		if(a[i]=='3')	ans[3]++;
		if(a[i]=='4')	ans[4]++;
		if(a[i]=='5')	ans[5]++;
		if(a[i]=='6')	ans[6]++;
		if(a[i]=='7')	ans[7]++;
		if(a[i]=='8')	ans[8]++;
		if(a[i]=='9')	ans[9]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<ans[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
} 
