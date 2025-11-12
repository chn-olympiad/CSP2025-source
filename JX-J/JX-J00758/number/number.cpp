#include<bits/stdc++.h>
using namespace std;
string s;
long long box[13];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0' && s[i]<='9') box[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(box[i] != 0)
		{
			cout<<i;
			box[i]--;
		}
	}
	return 0;
}
