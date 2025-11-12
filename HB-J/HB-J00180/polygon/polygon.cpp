#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005]={0},ans;
void dbx(int l,int x,int mx,int d){
    if(l==0){
        if(x>mx*2){
            ans=(ans+1)%998244353;
        }
        return ;
    }
    for(int i=d;i<=n-l+1;i++){
        dbx(l-1,x+a[i],a[i],i+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int l=3;l<=n;l++){
        dbx(l,0,0,1);
    }
    cout<<ans;
    return 0;
}
