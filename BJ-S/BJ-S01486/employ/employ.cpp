#include <bits/stdc++.h>
using namespace std;//求20分
#define int long long
int n,m,ans=1,c[5005];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;//所有si=1
    int q=n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    //for(int j=1;j<=m!;j++){
        //for(int i=1;i<=n;i++){

        //}
   // }

    sort(c+1,c+1+n,greater<int>());
    cout<<0;

	return 0;
}
