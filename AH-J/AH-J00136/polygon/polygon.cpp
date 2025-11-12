#include<bits/stdc++.h>
using namespace std;
long long n;
long long a;
long long sum;
long long maxn=INT_MIN;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
		maxn=max(maxn,a);
		sum+=a;
    }
    if(n<3)
    {
		cout<<"0";
		return 0;
	}
    if(n==3)
    {
		if(maxn*2<sum)
		{
			cout<<"1";
			return 0;
		}
		else
		{
			cout<<"0";
			return 0;
		}
	}
    return 0;
}
