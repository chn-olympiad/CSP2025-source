#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n;
int cnt,mx;
long long sum;
struct node{
    int s,t;
} a[5005];
void bfs(int m,int cnt,int mx,int j){
    int q=m;
    if(m==0){
        if(cnt>mx*2){
            sum=(sum+1)%998244353;
        }
        return ;
    }
    for(int i=j+1;i<=n;i++){
        a[i].t=1;
        bfs(m-1,cnt+a[i].s,max(mx,a[i].s),i);
        a[i].t=0;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].s;
    }
    for(int i=1;i<=n;i++){
        a[i].t=0;
    }
    bool o=0;
    for(int i=1;i<=n;i++){
        if(a[i].s!=1){
            o=1;
        }
    }
    if(o==0){
        for(int i=n-2;i>=1;i--){
            sum=(sum+i)%998244353;
        }
        cout<<sum%998244353;
        return 0;
    }
    int m=3;
    while(m<=n){
        bfs(m,cnt,mx,0);
        m++;
    }
    cout<<sum%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
