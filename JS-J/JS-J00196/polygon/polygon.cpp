#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005];
    cin>>n;
    int maxn=0,maxnn;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(maxn<a[i]){
            maxn=a[i];
            maxnn=i;
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(i==maxnn){
            continue;
        }
        else{
            sum+=a[i];
        }
    }
    if(sum>maxn){
        cout<<1;
    }
    else cout<<0;
    return 0;
}
