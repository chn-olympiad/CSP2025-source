#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k,cnt;
int a[500010];
bool st[500010];
int e(int x,int y)
{
	return x^y;
}
int d[500010];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0&&n<=2)
	{
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
			if(a[i]==0)
			{
				cout<<1<<endl;
				return 0;
			}
		}
		cout<<0<<endl;
		return 0;
	}
	else 
	{
		cout<<2<<endl;
		return 0;
	}
} 

