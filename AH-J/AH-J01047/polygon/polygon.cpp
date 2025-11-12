#include<bits/stdc++.h>
using namespace std;
int n,he,maxn=-1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        he+=a[i];
        maxn=max(maxn,a[i]);
    }
    if(n<3){
        cout<<0;
    }else{
        if(he>2*maxn){
            cout<<1;
        }eles{
            cout<<0;
        }
    }
    return 0;
}
