#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int j=0;
	for(int i=0;i<n.size();i++)
	{
		if(n[i]>='0'&&n[i]<='9')
		{
			a[++j]=int(n[i])-48;
		}
	}
	sort(a+1,a+j+1);
	for(int i=j;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}