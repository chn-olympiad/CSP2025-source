#include<bits/stdc++.h>
using namespace std;

const int N=1e6+6;

int a[N];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),cnt=0;
	for(int i=0;i<l;i++)
	{
		if(isdigit(s[i]))
			a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--)
		cout<<a[i];
	return 0;
}
