#include<bits/stdc++.h>
using namespace std;
string a;
int cnt,li[900000],b;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	b=a.size()-1;
	for(int i=0;i<=b;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			cnt++;
			li[cnt]=a[i]-'0';
		}
	}
	sort(li,li+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		cout<<li[i];
	}
	return 0;
}
