#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
string s;
int a[N],t=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l = s.size();
	for(int i=0; i<l; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			t++;
			a[t] = s[i] - '0';
		}
	}
	sort(a,a+t);
	reverse(a,a+t);
	for(int i=0; i<t; i++)
	{
		cout<<a[i];
	}
	return 0;
}
