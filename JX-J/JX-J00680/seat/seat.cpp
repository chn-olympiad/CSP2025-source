#include<bits/stdc++.h>
using namespace std;
int a[200];
int  cmp(int v,int b){
    return v>b;
    }
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int dd=a[1];
    int f;
    sort(a+1,a+1+m*n,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==dd) f=i;
    }
    int o=1;
    while(o*n<f){
        o++;
    }
    if(o%2==1){
        cout<<o<<" "<<f-n*(o-1);
    }
    else cout<<o<<" "<<n+1-(f-n*(o-1));
    return 0;
    }
