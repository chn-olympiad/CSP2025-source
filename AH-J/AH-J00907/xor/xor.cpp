#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,k,sum,ans,l,r,mid;
int a[N];
bool fa=1,fb=1;
bool cheak(int x){
    int tot=0,sum=0,j=1;
    bool CCF=0;
    for(int i=1;i<=n;i++){
        sum=0;
        for(j=i;j<=n;j++){
            sum^=a[j];
            if(sum==k){
                tot++;
                CCF=1;
                break;
            }
        }
        if(tot==x) return 1;
        if(CCF) i=j;
    }
    return 0;
}
map<int,bool>mp;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1&&a[i]!=a[i-1]) fa=0;
        if(a[i]>1) fb=0;
    }
    if(fa&&a[1]==0&&k==0){
        cout<<n;
        return 0;
    }
    if(fa&&k==0){
        cout<<n/2;
        return 0;
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            if(mp.count(a[i])){
                mp.clear();
                ans++;
            }
            else mp[a[i]]=1;
            if(a[i]==0){
                mp.clear();
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    if(fb){
        for(int i=1;i<=n;i++){
            sum^=a[i];
            if(sum==k){
                ans++;
                sum=0;
            }
        }
        cout<<ans;
        return 0;
    }
    /*
    r=n;
    while(l<=r){
        mid=(l+r)>>1;
        if(cheak(mid)) l=mid+1;
        else r=mid-1;
    }
    cout<<r;
    */
    int tot=0,sum=0,j=1;
    bool CCF=0;
    for(int i=1;i<=n;i++){
        sum=0;
        for(j=i;j<=n;j++){
            sum^=a[j];
            if(sum==k){
                tot++;
                CCF=1;
                break;
            }
        }
        if(CCF) i=j;
    }
    cout<<tot;
    return 0;
}
/*
5 2
3 3 2 1 3
*/
