#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a<b;
}
long long int n,a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    long long int s,j;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    if(n==3){
        if(a[0]+a[1]>a[2]){
            cout<<1;
        }
        else cout<<0;
    }
    else{
        cout<<0;
    }
    return 0;
}
