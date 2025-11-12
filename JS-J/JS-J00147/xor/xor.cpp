#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll a[505050],s[505050];
ll l,r;
bool check(int x){
    int cnt=0,last=0;
    for(int i=1;i<=n;i++){
        for(int j=last;j<=i;j++){
            if((s[i]^s[j-1])==k){
                cnt++;
                last=i+1;
                break;
            }
        }
    }
    //cout<<cnt<<endl;
    if(cnt>x) return true;
    return false;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=a[i]^s[i-1];
    }
    l=0,r=n;
    while(1<r){
        if(l==r) break;
        int mid=(r-l)/2+l;
        if(check(mid)){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    cout<<l<<'\n';
    return 0;
}
//300pts