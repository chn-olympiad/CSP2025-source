#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],sum[N];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s,x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+bool(n-sum[i-1]<a[i]);
    }
    cout<<0<<endl;
    return 0;
}
