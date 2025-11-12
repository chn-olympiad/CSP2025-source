#include <bits/stdc++.h>
using namespace std;
int a[5010],n;
long long t=0;
void d(int m,int o,int p,int v,int l){
    int i;
    if(p==l+1){
        if(o>m*2){
            t=t+1;
        }
        return ;
    }
    for(i=v+1;i<=n;i++){
        d(max(m,a[i]),o+a[i],p+1,i,l);
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=3;i<=n;i++){
        d(0,0,1,0,i);
    }
    cout<<t%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
