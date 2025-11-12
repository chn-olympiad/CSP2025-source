#include<bits/stdc++.h>
using namespace std;
int n,k;
const int maxn = 5e5+5;
int a[maxn];
int dp[maxn];
int cnt =1 ;
int ans;
bool Ta = 1,Tb = 1;
void ta(){
    if(k>=2){
        cout<<0;
        return ;
    }
    else if(k == 1){
        cout<<n;
        return ;
    }
    else{
        cout<<n/2;
        return ;
    }
}
void tb(){
    if(k>=2){
        cout<<0;
        return ;
    }
    if(k == 1){
        for(int i = 1;i<=n;i++){
            if(a[i] == 1){
                ans++;
            }
        }
        cout<<ans;
        return ;
    }
    else {
        for(int i = 1;i<=n;i++){
            if(a[i] == 0) ans++;
            if(a[i] == 1&&a[i+1] == 1) ans++;

        }
        cout<<ans;
        return ;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) Ta = 0;
        if(a[i]>1) Tb = 0;
    }
    if(Ta){
        ta();
    }
    if(Tb){
        tb();
    }
}
