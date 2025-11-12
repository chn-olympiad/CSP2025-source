#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int a[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    bool f1=1,f01=1;
    int kt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1&&a[i]){
            f1=0;
            f01=0;
        }
        if(a[i]!=1){
            f1=0;
        }
        if(a[i]==k)
            kt++;
    }
    if(f1){
        if(k)
            cout<<n<<'\n';
        else
            cout<<n/2<<'\n';
        return 0;
    }
    if(f01){
        int ct0=0,ct1=0;
        int t=1;
        for(int i=1;i<=n;i++){
            if(a[i]){
                ct1++;
                if(a[i+1])
                    t++;
                else{
                    ct0+=t/2;
                    t=1;
                }
            }
            else
                ct0++;
        }
        if(k)
            cout<<ct1<<'\n';
        else
            cout<<ct0<<'\n';
        return 0;
    }
    cout<<kt<<' ';
    return 0;
}
