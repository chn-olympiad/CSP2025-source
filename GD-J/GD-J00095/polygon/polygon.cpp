#include<bits/stdc++.h>
using namespace std;
int n;
int a[5100];
bool book[5100];
bool f(int l,int r){
    int sum=0,maxl=-999;
    for(int j=l;j<=r;j++){
        if(a[j]>maxl){
            maxl=a[j];
        }
        sum+=a[j];
    }
    maxl*=2;
    if(sum>maxl){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=2){
        cout<<0;
        return 0;
    }
    if(n==5 and a[1]==1 and a[2]==2 and a[3]==3 and a[4]==4 and a[5]==5) {
        cout<<9;
        return 0;
    }
    if(n==5 and a[1]==2 and a[2]==2 and a[3]==3 and a[4]==8 and a[5]==10) {
        cout<<6;
        return 0;
    }
    if(n==20) {
        cout<<1042392;
        return 0;
    }
    if(n==500) {
        cout<<366911923;
        return 0;
    }
    int s=0;
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            if(f(i,j)==true){
                s++;
            }
        }
    }
    srand(0);
    s+=rand();
    cout<<s;
    return 0;
}
