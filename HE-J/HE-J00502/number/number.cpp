#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int l=0,a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			l++;
			a[l]=s[i]-'0';
		}
	}
	sort(a+1,a+1+l);
	for(int i=l;i>=1;i--)
		cout<<a[i];
	return 0;
}
