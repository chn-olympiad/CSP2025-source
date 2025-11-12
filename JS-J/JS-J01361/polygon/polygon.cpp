#include<bits/stdc++.h>
using namespace std;
int a[5002],prefix[5002];/*
int sum(int left,int right){
    return prefix[right]-prefix[left]+a[left];
}*/
int result,sum;int n;
void dfs(int dep,int sum,int maxindex,int choose){
    if((n-dep==1)&&(choose<1)) return;
    if((n-dep==0)&&(choose<2)) return;
    if(dep>n){
        if(choose<3||sum<=(a[maxindex]*2)) return;
        if(sum>a[maxindex]*2) result++;
        return;
    }
    dfs(dep+1,sum+a[dep],dep,choose+1);
    dfs(dep+1,sum,maxindex,choose);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        prefix[i]=prefix[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    dfs(1,0,-1,0);
    /*
    for(int l=1;l<=n-2;l++){
        for(int r=l+2;r<=n;r++){
            if(sum(l,r)>(a[r]*2)){
                result++;
        }
    }*/
    cout<<result;
    return 0;
}
