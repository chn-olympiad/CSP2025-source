#include<bits/stdc++.h>
using namespace std;
string arr;
int a[1000005],s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>arr;
	int len=arr.size();
	for(int i=0;i<len;i++)
	{
		if(arr[i]>='0'&&arr[i]<='9') a[++s]=arr[i]-'0';
	}
	sort(a+1,a+s+1);
	for(int i=s;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
