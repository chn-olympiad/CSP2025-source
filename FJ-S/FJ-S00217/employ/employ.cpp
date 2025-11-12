#include<bits/stdc++.h>
using namespace std;

const int MAXN=506;
long n,m,c[MAXN],t1,t2,ans;
string s;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s;
	for(long i=0;i<n;i++){
		cin>>c[i];
		if(!c[i]) t1++; 
	}
	long l=s.length();
	for(long i=0;i<l;i++)
		if(s[i]=='0')
			t2++;
	
	if(n-t1<m||n-t2<m)
	{
		cout<<0;
		return 0;
	}
////// Test 15 //////
	if(m==n)
	{
		ans=1;
		for(long i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
////// Test 15 //////
	
	return 0;
}
