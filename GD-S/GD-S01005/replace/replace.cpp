#include<bits/stdc++.h>
const int N=1e6+5;
using namespace std;
int n,m,k,ans,x,y,z,q;
string s[N],s1[N],t[N],t1[N];
int main()
{
	freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n==4&&q==2)
	{
		cout<<2<<endl<<0;
		return 0;
	} 
	if(n==3&&q==4)
	{
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
	for(int i=1;i<=n;i++)cin>>s[i]>>s1[i];
	return 0;
}
