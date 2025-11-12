#include<bits/stdc++.h>
using namespace std;
int n,zzz=0;
int a[1000005];
long long s;
string b;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	for(int i=0;i<int(sizeof(b));i++)
	{
		if(b[i]>='0'&&b[i]<='9')
		{
			s++;
			a[s]=(b[i]-'0');
		}
	}
	sort(a+1,a+1+s);
	for(int i=s;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
