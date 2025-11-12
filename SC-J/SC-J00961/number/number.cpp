#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define dow(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
string s;
int a[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;s=" "+s; 
	int n=s.size()-1;
	rep(i,1,n)
	  if('0'<=s[i]&&s[i]<='9')
	    a[s[i]-'0']++;
	bool vis=0;
	dow(i,9,0)
	  rep(j,1,a[i])
	    cout<<i;
	return 0;
}