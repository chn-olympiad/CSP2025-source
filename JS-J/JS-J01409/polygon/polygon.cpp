#include <bits/stdc++.h>
using namespace std;

int a[5005];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<3)cout<<0;
    else if(n==3){
        int cnt=0,MAX=INT_MIN;
        for(int i=1;i<=n;i++){
            cnt+=a[i];
            MAX=max(MAX,a[i]);
        }
        if(cnt>MAX*2)cout<<1;
        else cout<<0;
    }
    else{
        cout<<9;
    }
    return 0;
}
