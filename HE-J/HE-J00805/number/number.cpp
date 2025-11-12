//rp++
#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
vector<int> a(1000001);
bool cmp(int a,int b) {return a>b;}
int rp=0;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=(s[i]-'0');
			rp++;
		}
	}
	int n=s.length();
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<rp;i++)
	{
		cout<<a[i];
	}
	return 0;
}
//rp++
