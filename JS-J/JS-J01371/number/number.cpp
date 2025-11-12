#include <bits/stdc++.h>
using namespace std;

string str;
long long n,m;
int arr[1000010];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	n=str.length();
	for(int i=0;i<n;i++)
	{
		if(str[i]<='9'&&str[i]>='0')
		{
			arr[m]=str[i]-'0';
			m++;
		}
	}
	sort(arr,arr+m);
	for(int i=m-1;i>=0;i--)
	{
		cout<<arr[i];
	}
	return 0;
}
