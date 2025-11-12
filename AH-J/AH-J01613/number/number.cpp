#include<bits/stdc++.h>
using namespace std;
char d;
long long n;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
string b;
cin>>a;
long long c=a.size();
for(int i=0;i<c;i++)
{
if(a[i]>='0'&&a[i]<='9')
{
b[n]=a[i];
n++;
}
}
for(int i=0;i<n;i++)
{
	for(int j=i+1;j<n;j++)
	{
		if(b[i]<b[j])
		{
				swap(b[i],b[j]);
		}
	}
}
for(int i=0;i<n;i++)
{
	cout<<b[i];
}
return 0;
}
