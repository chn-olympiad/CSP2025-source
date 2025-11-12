#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b;
	cin>>a;
	int len=a.size();
	for(int i=0; i<len; i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			b=b+a[i];
		}
	}
	sort(b.begin(),b.end());
	int len2=b.size();
	for(int i=len2-1; i>=0; i--)
	{
		cout<<b[i];
	}
}
