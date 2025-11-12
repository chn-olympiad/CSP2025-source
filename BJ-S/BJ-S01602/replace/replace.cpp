#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
const int B = 131;
typedef unsigned long long ull;
int n,q,ans;
string s[N][2];
ull hs[N][2];
int ls[N],lt;
ull h1[N],h2[N],powB[N];
ull hashB(string &str)
{
	ull ret = 0ull;
	int len = str.length();
	for (int i = 1;i <= len;i++)
	{
		ret = ret * B + str[i-1];
		//cout<<str[i-1]<<"chuli\n";
		//cout<<"hashB:"<<i<<","<<ret<<'\n';
	}
	return ret;
}
ull queryh1(int l,int r)
{
	if (l > r) return 0ull;
	return h1[r] - h1[l-1] * powB[r-l+1];
}
ull queryh2(int l,int r)
{
	if (l > r) return 0ull;
	return h2[r] - h2[l-1] * powB[r-l+1];
}
bool check(int id)
{
	//s[id][0],s[id][1];
	int len = ls[id];
	for (int i = 1;i+len-1 <= lt;i++)
	{
		int l = i,r = i+len-1;
		//cout<<"l,r:"<<l<<" "<<r<<",id="<<id<<'\n';
		if (queryh1(l,r) == hs[id][0])
		{
			//cout<<id<<","<<l<<" "<<r<<'\n';
			if (queryh1(1,l-1) == queryh2(1,l-1) && queryh1(r+1,n) == queryh2(r+1,n) && queryh2(l,r) == hs[id][1])
			{
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//zhushi jide shan
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	powB[0] = 1ull;
	for (int i = 1;i <= n+1;i++)
	{
		powB[i] = powB[i-1] * B;
	}
	for (int i = 1;i <= n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		ls[i] = s[i][0].length();
		hs[i][0] = hashB(s[i][0]);
		hs[i][1] = hashB(s[i][1]);
		//cout<<s[i][0]<<":"<<hs[i][0]<<'\n';
	}
	string t1,t2;
	//if (q == 1)
	//{
		//cin>>t1>>t2;
		//return 0;
	//}
	while (q--)
	{
		ans = 0;
		cin>>t1>>t2;
		if (t1.length() != t2.length())
		{
			cout<<"0\n";
			continue;
		}
		lt = t1.length();
		for (int i = 1;i <= lt;i++)
		{
			h1[i] = h1[i-1] * B + t1[i-1];
			h2[i] = h2[i-1] * B + t2[i-1];
			//cout<<t1[i-1]<<"chuli\n";
			//cout<<"h1["<<i<<"]="<<h1[i]<<'\n';
		}
		//cout<<queryh1(1,5)<<" "<<hs[1][0]<<'\n';
		for (int i = 1;i <= n;i++)
		{
			if (check(i))
			{
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
