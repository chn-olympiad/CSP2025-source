#include<bits/stdc++.h>
using namespace std;
int n,maxn=-1,num=0;
int a[50005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        num+=a[i];
    }if(maxn*2<num){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
