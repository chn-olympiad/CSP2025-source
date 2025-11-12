#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    int a[1000001];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        if((a[1]+a[2]+a[3])>(max({a[1],a[2],a[3]})*2)){
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    sort(a+1,a+1+n);
    if(a[n]==a[1]){
        cout<<n;
        return 0;
    }
}
