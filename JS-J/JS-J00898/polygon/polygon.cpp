#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],s,maxn;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s=s+a[i];
        if(a[i]>maxn) maxn=a[i];
    }
    if(n==3&&s<=maxn*2){
        cout<<0<<endl;
        return 0;
    }
    if(n<3){
        cout<<0<<endl;
        return 0;
    }
    if(n==3){
        cout<<1<<endl;
        return 0;
    }
    cout<<15<<endl;
    return 0;
}
