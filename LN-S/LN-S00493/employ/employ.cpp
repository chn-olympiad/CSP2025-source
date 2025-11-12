#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,a[100000],ans;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans+=a[i];
    }
    cout<<ans;
    return 0;
}
