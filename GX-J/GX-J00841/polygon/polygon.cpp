#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if (n<3){
        cout<<0;}
    else if(n==3){
        int a[n],maxn=0,sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];}
        for(int i=0;i<n;i++){
            sum+=a[i];
            maxn=max(a[i],maxn);}
        if  (sum>maxn*2){
            cout<<1;}
        else{
            cout<<0;}}
}
