#include<bits/stdc++.h>
using namespace std;
int b[1000010],ant=0;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>=48&&a[i]<=57)
		{
			ant++;
			b[ant]=a[i]-'0';
		}
	}
	sort(b+1,b+ant+1,cmp);
	for(int i=1;i<=ant;i++)
	{
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
}