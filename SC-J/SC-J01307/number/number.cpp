#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int a[15];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	s=" "+s;
	int len=s.size()-1;
	for(int i=1;i<=len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[(int)(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			printf("%lld",i);
		}
	}
	return 0;
}
//freopen
//feropen
//never gonna give you up
//T1 is so hard
//I can't do it 
/*
oooooooo..rrrrrrr.zzzzzzzz
o......o.r..............z.
o......o.r.............z..
o......o.r............z...
o......o.r...........z....
o......o.r..........z.....
o......o.r.........z......
oooooooo.r........zzzzzzz
Gei duiye ketou le
RP++
*/