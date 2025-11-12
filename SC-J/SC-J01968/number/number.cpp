#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string in;
short s[N];
int cd,top=1;
int main()
{
//	freopen("number4.in","r",stdin);
//	freopen("number4.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>in;
	cd=in.size();
	for(int i=0;i<cd;i++)
	{
		if(in[i]>='0'&&in[i]<='9')
		{
			s[top]=in[i]-'0';
			top++;
		}
	}
	sort(s+1,s+top);
	if(s[top-1]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=top-1;i>=1;i--)
	{
		cout<<s[i];
	}
	return 0;
}