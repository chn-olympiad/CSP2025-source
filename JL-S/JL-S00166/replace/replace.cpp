#include <bits/stdc++.h>
using namespace std;
long long n,q;
#define N 100005
long long a[N];
int ans=0;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)    break;
		else
		{
			while(n--)
			{
				a[i]++;
				n--;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
