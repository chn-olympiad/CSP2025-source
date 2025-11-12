#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a1;
	cin>>a1;
	int t=a1.size();
	int cnt=-1;
	for(int i=0;i<t;i++)
	{
		if(a1[i]>='0'&&a1[i]<='9')
		{
			cnt++;
			a[cnt]=a1[i]-48;
		}
	}
	for(int i=0;i<cnt+1;i++)
		for(int j=i+1;j<cnt+1;j++)
			if(a[i]<a[j])
				swap(a[i],a[j]);
	for(int i=0;i<cnt+1;i++)
		cout<<a[i];
	return 0;
}
