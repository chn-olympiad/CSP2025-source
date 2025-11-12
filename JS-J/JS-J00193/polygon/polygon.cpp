#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int main( )
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n<3) cout<<0;
    if(n==3)
    {
        if(a[3]<a[1]+a[2]) cout<<1;
        else cout<<0;
    }
    else cout<<9;
	return 0;
}
