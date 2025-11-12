#include <bits/stdc++.h>
using namespace std;

const int N=20;
int box[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9') box[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(box[i]--) cout<<i;
	}
	cout<<endl;
	return 0;
}