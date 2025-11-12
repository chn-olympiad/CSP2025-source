#include<bits/stdc++.h>
using namespace std;

string s;
int arr[1000005];
int p=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(int(s[i])>=48&&int(s[i])<=57)
		{
			arr[p]=s[i];
			p++;
		}			
	}
	sort(arr+1,arr+p);
	for(int i=p-1;i>=1;i--)
		cout<<arr[i]-48;
	return 0;
}
