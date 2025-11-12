#include <bits/stdc++.h>
using namespace std;
int n,k,ans=0;
long long a[500001];
bool jh(int l,int r,int k){
    int tnt=0;
    for(int i=l;i<=r;i++){
        tnt=tnt^a[i];
    }
    if(tnt==k)return 1;
    return 0;
}
int jj(int l,int r){
    if(l>r||r>n)return ans;
    if(jh(l,r,k)){
        ans++;
        l=r+1;
        r+=1;
    }
    else r++;
    return jj(l,r);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<(jj(1,1));
    return 0;
}
