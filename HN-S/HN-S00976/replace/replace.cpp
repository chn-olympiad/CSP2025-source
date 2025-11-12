#include<bits/stdc++.h>
using namespace std;
long n,q;
string s1,s2;
int main()
{
	freopen("replace.in.txt","r",stdin);
	freopen("replace.out.txt","w",stdout);
	cin>>n>>q;
	for(long i=1;i<=n+q;i++)
	{
		cin>>s1>>s2;
		
	}
	for(long i=1;i<=q;i++)
	{
		if(i%2==1)
		cout<<(n-i)%12;
		else
		cout<<(q+n-i+1)%13;
	}
	return 0;
}
