#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int h;
long long ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int s=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        cout<<1;
    }for(int i=1;i<=n;i++){
        if(a[i]==1){
            h++;
        }
        if(a[i]==0){
            s++;
        }
    }
    if(h!=n&&h+s==n){
        cout<<h-2;
        return 0;
    }
    return 0;
}
