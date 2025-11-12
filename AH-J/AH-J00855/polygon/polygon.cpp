#include<bits/stdc++.h>
using namespace std;
int a[10010];
int n;
int sum;
int maxn;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n==3){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
            maxn=max(maxn,a[i]);
        }
        if(sum>maxn*2){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cout<<(n-1)*(n-2)/2;
    }
    return 0;
}
