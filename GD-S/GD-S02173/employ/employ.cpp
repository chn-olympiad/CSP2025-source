#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int MOD=998244353;
long long n,m,a[N],ans=0;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool f=true;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		 f=false;
	} 
	for(int i=1;i<=n;i++)
	 cin>>a[i]; 
	if(f==false)
	{
		cout<<1<<endl;
		return 0;
	}
	ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}
