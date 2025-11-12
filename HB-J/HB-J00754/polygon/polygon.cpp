#include<bits/stdc++.h>
using namespace std;
int m,n,a[100000],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        if(a[i]==a[i+1]){
            m=m-1;
            ans++;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            ans++;
        }
    }
    cout<<ans-1;
    return 0;
}
