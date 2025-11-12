#include<bits/stdc++.h>
using namespace std;
int cntone(int n){
    int a=0;
    while(n!=0){
        n=n&(n-1);
        a++;
    }
    return a;
}
int a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    if(n==3){
        int x,y,z;
        cin>>x>>y>>z;
        if(max(max(x,y),z)*2<x+y+z){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=7;i<(1<<n);i++){
            if(cntone(i)<3) continue;
            int mx=-1;
            for(int j=0;j<n;j++){
                if(i&(1<<j)!=0){
                    cnt+=a[j];
                    mx=max(mx,a[j]);
                }
            }
            if(mx*2<cnt){
                ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}
