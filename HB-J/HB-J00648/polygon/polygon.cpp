#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[5100]={0};int n,ans=0,one=0;
bool vis[5100]={0};
void dg(int x){
    if(x==n){
        long long sum=0;
        int maxn=-1;
        for(int i=0;i<n;i++){
            if(vis[i]){
                one++;
                maxn=max(maxn,a[i]);
                sum+=a[i];}
        }
        if(sum>2*maxn&&one>=3)ans++;
        return;
    }
    for(int i=0;i<=1;i++){
        vis[x]=i;
        dg(x+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dg(0);
    cout<<ans;
    return 0;
}
