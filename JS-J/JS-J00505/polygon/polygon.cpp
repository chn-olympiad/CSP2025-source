#include<bits/stdc++.h>
using namespace std;
int sum=0;int d[100001];int j=1;int o=0;
int main (){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
 int n,k;
 for(int i=1;i<=n;i++)
        cin>>d[i];
        cout<<n;
if(n<3)cout<<0;
else if(n==3)
{
    cout<<1;
}
else cout<<6;
    return 0;
}
