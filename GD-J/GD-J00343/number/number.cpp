#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
string a;

int vis[9];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>=48 && a[i]<=57)
		{
			vis[a[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(vis[i]==0) continue;
		else
	    {
	    	for(int j=0;j<vis[i];j++)
	    	{
	    		cout<<i;
			}
		}
	}
	cout<<"\n";
	
	return 0;
}
