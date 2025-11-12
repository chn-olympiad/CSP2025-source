#include<iostream>
#include<cmath>
#include<algorithm>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define wt(s) (s)=" "+(s)
using namespace std;
const int maxn=1000005;
ll n,m,a[maxn],cnt=0;
string s,ans;
inline void fre()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
int main()
{
	IOS
	fre();
	cin>>s;
	n=s.size();
	wt(s);
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
} 
