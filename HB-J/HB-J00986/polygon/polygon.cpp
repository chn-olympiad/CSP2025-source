#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,maxx=-1,ans;
bool f=1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        if(a[i]!=1)

            f=0;
        maxx=max(a[i],maxx);
    }
    if(maxx*2<sum)
        cout<<1;
    else
        cout<<0;
    return 0;
}
