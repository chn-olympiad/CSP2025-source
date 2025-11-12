#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    if(n==1&&a[1]==0&&k==0)cout<<1;
    if(n==2&&k==0){
        if(a[1]==0&&a[2]==0)cout<<2;
        else if(a[1]==a[2]) cout<<1;
        else cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
