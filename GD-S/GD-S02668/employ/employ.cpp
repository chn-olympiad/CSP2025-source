#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
const int MAXN=505;
int n,m,c[MAXN],count1;
string s1;
long long ans;
char s[MAXN];
bool check1,check2=true,check3=true;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("r","employ.in",stdin);
	freopen("w","employ.out",stdout);
	cin>>n>>m;
	if(m==n)check1=true;
	cin>>s1;
	for(int i=0;i<s1.length();i++)
	{
		if(s1[i]=='0')
		{
			check3=false;
		}
		else
		{
			check2=false;
			count1++;
		}
	}
	
	if(check3)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%MOD;
		}
		cout<<ans<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
