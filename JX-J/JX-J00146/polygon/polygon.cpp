#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    int h=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=3){
        for(int i=1;i<=n;i++){
            h+=a[i];
        }
        if(h<=2*a[n]){
            cout<<0;
            return 0;
        }
        else{
            cout<<1;
            return 0;
        }
    }
    return 0;
}
