#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxn,cnt=0;
    if(n<=3){
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
            cnt+=a[i];
        }
        if(cnt>maxn*2){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else
        cout<<1;
    return 0;
}

