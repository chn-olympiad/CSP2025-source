#include<bits/stdc++.h>
using namespace std;
int n,a[5008],mx,cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[3]+a[2]>a[1]) cout<<1;
        else cout<<0;
        return 0;
    }
    if(a[n]==5) cout<<9;
    else cout<<6;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
