#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000000];
int ans=0;
int main()
{
	freopen("number.in"," r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		b[i]=a[i];
		if(a[i]==0)
		ans++;
	}
	sort(b+1,b+1+a.size());
	for(int i=1;i<=a.size();i++)
	{
		if(b[i]!=0)
		cout<<b[i];
	}
	for(int i=1;i<=ans;i++)
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
