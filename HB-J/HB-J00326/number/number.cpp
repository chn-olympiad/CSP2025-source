#include <bits/stdc++.h>
using namespace std;
const int D=1e6;	// D=10^6
string s;
int num[D];
int numlen=0;
int len;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(num,-1,sizeof(num));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		char curr=s[i];
		if(curr<='9'&&curr>='0')
		{
			num[numlen]=curr-'0';
			numlen++;
		}
		/*
		cout<<curr-'0'<<endl;
		cout<<'9'-'0'<<endl;
		cout<<'0'-'0'<<endl;
		cout<<"numlen: "<<numlen<<endl;
		*/
	}
	sort(num,num+numlen);
	for(int i=numlen-1;i>=0;i--)
	{
		cout<<num[i];
	}
	return 0;
}
