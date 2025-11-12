#include<bits/stdc++.h>
using namespace std;
string a;
long long b[1000000],c;
int z(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	if(a<=0)
	{
		cout<<"You have no egg!";
	}
	for(int i=0;i<a.size();i++)
    {
		if(a[i]>='0'&&a[i]<='9')
		{
			b[++c]=a[i]-'0';
		}
	}
	sort(b+1,b+1+c,z);
	for(int i=1;i<=c;i++)
    {
		cout<<b[i];
	}
    return 0;
}
