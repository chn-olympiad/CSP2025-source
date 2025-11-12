#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
    }
    long long sum=1;
    for(int i=1;i<=n;i++){
        sum*=i;
        sum=sum%988244353;
    }
    cout<<sum;
    return 0;
}
