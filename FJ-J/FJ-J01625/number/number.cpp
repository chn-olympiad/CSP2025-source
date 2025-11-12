#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string a,s;
int b[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a+=s[i];
		}
	}
	l=a.size();
	for(int i=0;i<a.size();i++)
	{
		b[i]=a[i]-48;
	}
	sort(b,b+l,cmp);
	for(int i=0;i<l;i++)
	{
		cout<<b[i];
	}
	return 0;
 } 
