#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,c1=0,c0=0;
    bool vis1=true,vis2=true;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(a[i]==0){
            c0++;
        }else if(a[i]==1){
            c1++;
        }
        if(a[i]!=1){
            vis2=false;
        }
        if(a[i]>1){
            vis1=false;
        }
    }
    if(vis2){
        if(k==1){
            cout<<n;
        }else if(k==0){
            cout<<n/2;
        }else{
            cout<<0;
        }
        return 0;
    }
    if(vis1){
        if(k==1){
            cout<<c1;
        }else if(k==0){
            int cnt=0;
            bool vis[n+5];
            for(int i=1; i<=n; i++){
                vis[i]=true;
            }
            for(int i=1; i<=n; i++){
                if(a[i]==1){
                    if(a[i]==a[i-1] && vis[i-1] && (i-1)>=1){
                        cnt++;
                        vis[i-1]=false;
                        vis[i]=false;
                    }else if(a[i]==a[i+1] && vis[i+1] && (i+1)<=n){
                        cnt++;
                        vis[i]=false;
                        vis[i+1]=false;
                    }
                }
            }
            cout<<cnt+c0;
        }else{
            cout<<0;
        }
        return 0;
    }
    cout<<0;
    return 0;
}
