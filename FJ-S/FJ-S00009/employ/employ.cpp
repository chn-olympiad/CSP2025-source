#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505];
string s;
bool ok=1;
long long jc(int n)
{
	if(n==1)
	return 1;
	else 
	    return (n*(jc(n-1)))%998244353;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	memset(c,0,sizeof(c));
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	    cin>>c[i];
    for(int i= 1;i<=s.size();i++)
    {
    	if(s[i]=0)
    	    ok=0;
	}
	if(ok==1)
	    cout<<jc(n)/3;
	return 0;
}
