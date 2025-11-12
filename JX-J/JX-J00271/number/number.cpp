#include<bits/stdc++.h>
using namespace std;
string a;
int b[1001];
bool asd(int d,int g)
{
	return d>g;
}
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);

int o=0;
cin>>a;
for(int i=0;i<int(a.size());i++)
{
	if(a[i]>='0'&&a[i]<='9')
	{
		b[o]=a[i]-'0';
		o++;
	}
}
sort(b,b+o,asd);
for(int i=0;i<o;i++)
{
	cout<<b[i];
}
return 0;
}
