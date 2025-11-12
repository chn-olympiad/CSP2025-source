#include <bits/stdc++.h>
using namespace std;
int a[1000002];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	int top=1;
	cin>>s;
	int n=s.size();
	//cout<<n;
	for(int i=0;i<n;i++)
	{
		char sb=s[i];
		//cout<<sb;
		int sd=int(sb)-48;
		//cout<<sd;
		if(sd>=0 && sd<=9)
		{
			a[top++]=sb-'0';
			//cout<<1;
		}
	}
	sort(a+1,a+top);
	for(int i=top-1;i>=1;--i)
	{
		cout<<a[i];
	}
	//cout<<top;
	return 0;
}