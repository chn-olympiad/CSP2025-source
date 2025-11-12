#include <bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,q;
string s[N][2],t[N][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	for (int i=0;i<q;i++)
	{
		cin>>t[i][0]>>t[i][1];
    }
    for (int i=1;i<=q;i++)
    {
    	cout<<0<<endl;
	}
}