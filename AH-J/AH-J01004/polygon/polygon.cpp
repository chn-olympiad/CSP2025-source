#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long t;
bool f;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(a[1]+a[2]>a[3])
    {
		cout<<1
	}
    return 0;
}
