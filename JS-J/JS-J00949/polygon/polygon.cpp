#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			for(int p=j+1;p<=n;++p)
			{
				if(a[i]+a[j]+a[p]>2*max(a[i],max(a[j],a[p])))
					ans++;
			}
		}
	}
	cout<<ans<<"\n";
    return 0;
}
