#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool check1(int n){
    for(int i=0;i<n;i++){
        if(a[i]!=1)return false;
    }return true;
}
bool check2(int n){
    for(int i=0;i<n;i++){
        if(a[i]!=1&&a[i]!=0)return false;
    }return true;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    int k;
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    if(check1(n)&&k==0){
        cout<<n/2;
        return 0;
    }if(check2(n)&&k==1){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==1)cnt++;
        }
        cout<<cnt;
    }

    return 0;
}
