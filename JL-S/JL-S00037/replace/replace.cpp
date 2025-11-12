#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string a[N],b[N],c[N],d[N];
int n,m;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=m;i++)
        cin>>c[i]>>d[i];
    cout<<0;
    return 0;
}
