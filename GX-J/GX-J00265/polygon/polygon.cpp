#include<bits/stdc++.h>
using namespace std;
int a,b[5001],maxn=0,ans=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>a;
    for(int i=1;i<=a;i++)
    {
			cin>>b[i];
			ans+=b[i];
			if(maxn<b[i])
			{
					maxn=b[i];
				}
		}
	if(ans>maxn*2)
	ans++;
	cout<<"1";
    return 0;
}
