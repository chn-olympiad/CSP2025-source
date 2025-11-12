#include "bits/stdc++.h"
#define int long long
using namespace std;
const int N=5e5+10;
int n,k,cnt,c;
int a[N];
bool t[N];
bool f,r;
bool g(int l,int r){
    for(int i=l;i<=r;i++){
        if(t[i]) return 0;
    }
    return 1;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c+=(a[i]==1);
        if(a[i]!=1) f=1;
        if(a[i]!=1 && a[i]!=0) r=1;
    }
    if( !f && k==0){
        cout<<n/2;
        return 0;
    }
    if( !r && k==0){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0) cnt++;
            if(a[i]==1 && i<n && a[i+1]==1){
                i++;
                cnt++;
            }
        }
        cout<<cnt;
        return 0;
    }
    if( !r && k==1){
        cout<<c;
        return 0;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(g(i,j)){
                int x=0;
                for(int k=i;k<=j;k++){
                    x^=a[k];
                }
                if(x==k){
                    cnt++;
                    for(int k=i;k<=j;k++){
                        t[k]=true;
                    }
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
