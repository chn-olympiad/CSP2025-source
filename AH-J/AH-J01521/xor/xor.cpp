#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500050],he[500050];
string s[500050];
int n,k;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        he[i]=he[i-1]^a[i];
    }
    int maxn=0;
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(he[i]-he[j]==k){
                maxn=max(maxn,j-i);
            }
        }
    }
    cout<<maxn;
    return 0;
}

