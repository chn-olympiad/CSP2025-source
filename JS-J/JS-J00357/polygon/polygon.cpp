#include<bits/stdc++.h>
using namespace std;
int n;
int a[10005];
int vis1;
int maxx=0;
int sum;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            vis1=1;
        }
        maxx=max(maxx,a[i]);
        sum+=a[i];
    }
    if(vis1==0){
        cout<<n-2;
        return 0;
    }
    if(n==3&&a[1]+a[2]>a[3]&&sum>maxx*2){
        cout<<1;
    }
    else{
        cout<<0;
    }


    return 0;
}
