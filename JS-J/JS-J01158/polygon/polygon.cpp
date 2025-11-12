#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,x[5007],s1[5007],s2[5007],sum=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    s1[0]=0,s2[n+1]=0;
    sort(x+1,x+n+1);
    if(n==1||n==2){
        cout<<0;
        return 0;
    }
    if(n==3){
        cout<<1;
    }
    if(n==4){
        int ans=0;
        if(x[1]+x[2]+x[3]>x[4]) ans++;
        if(x[1]+x[2]>x[3]) ans++;
        if(x[1]+x[2]>x[4]) ans++;
        if(x[3]+x[2]>x[4]) ans++;
        if(x[1]+x[3]>x[4]) ans++;
        cout<<ans;
        return 0;
    }

    return 0;
}
