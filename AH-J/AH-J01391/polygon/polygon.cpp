#include<bits/stdc++.h>
using namespace std;
int n,a[15];
bool cmp(int a1,int b1){
    return a1>b1;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3) cout<<0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    if(n==3){
            int sum=0;
        for(int i=1;i<=3;i++){
            sum+=a[i];
        }
        if(sum>(a[1]*2)) cout<<1;
    }
    return 0;
}
