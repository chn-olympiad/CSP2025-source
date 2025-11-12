#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll lst[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>lst[i];
    }
    ll cnt=-1;
    for(int i=1;i<n;i++){
        ll l=i,r=i,ans=0,temp=0;
        while(r<=n){
            temp^=lst[r];
            if(temp==k){
                ans++;
                //cout<<l<<r<<endl;
                l=r+1;
                r=l;
                temp=lst[l];
            }
            r++;
        }
        cnt=max(cnt,ans);
    }
    cout<<cnt;
    return 0;
}
