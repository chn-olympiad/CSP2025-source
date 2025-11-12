#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	int i;
	cin>>s;
	if(i=s)
	{
		cout<<s;
	}
	for(char i=1;i<=length(s);i++)
	{
		cin>>a[i]; 
		if(a[i]>a[i-1])
		{
			swap(a[i],a[i-1]);
		}
		cout<<a[i];
    }
    return 0;
}