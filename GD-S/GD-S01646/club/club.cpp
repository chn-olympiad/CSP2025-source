#include <bits/stdc++.h>
using namespace std;
int t;
long long n,per[100005];
bool com(long long x,long long y)
{
	return x>y; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			int a,b;
			cin>>per[j]>>a>>b;
		}
		sort(per+1,per+n+1,com);
		cout<<per[1]+per[2];
    }
    return 0;
}
