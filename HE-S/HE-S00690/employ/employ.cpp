#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[500005];
int ans=1;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=m;i--) ans*=i;
    cout<<ans;
	return 0;
}
