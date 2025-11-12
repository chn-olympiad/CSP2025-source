#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[5005],n,ct,sct;
long long q[5005];
void dfs(int x,int s,int m){
    if(s-1==x){
        /*for(int i=1;i<s;i++){
            cout<<q[i]<<' ';
        }*/
        //cout<<endl;
        long long sum=0;
        for(int i=1;i<=x;i++){
            sum+=q[i];
        }
       // cout<<sum<<endl;
        if(sum>2*q[x]){
            sct++;
            return;
        }
    }
    for(int i=m+1;i<=n;i++){
        q[s++]=a[i];
        dfs(x,s,i);
        q[s]=0;
        s--;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        sct=0;
        dfs(i,1,0);
        //cout<<sct<<' ';
        ct+=sct%mod;
        ct%=mod;
    }
    cout<<ct;
    return 0;
}
