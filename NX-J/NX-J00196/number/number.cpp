#include<bits/stdc++.h>
#define N 1000005
#define M 100005
#define int long long
using namespace std;
string s;
int a[N],cnt;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	s=" "+s;
	for(int i=1;i<=l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
/*
zhi neng yong ying wen...
wo shi zcm,ye ke yi jiao wo weber,luogu ming jiao weberzcm,uid=786330
dui le,wo xiang shang mi huo xing wei da shang
int mian int mian int mian int mian int mian int mian
pian pian luogu mi huo xing wei da shang(doge
AwA
*/
