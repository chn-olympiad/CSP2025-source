#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
set<int> s;
void fangcode(){
    int b[500005];
    b[0]=0;
    for(int i=1;i<=n;i++){
        b[i]=(b[i-1] xor a[i]);
    }
    int ans=0,last=0;
    for(int i=1;i<=n;i++){
        for(int j=last+1;j<=i;j++){
            if((b[i] xor b[j-1])==k){
                ans++;
                last=i;
                break;
            }
        }
    }
    cout<<ans;
}
void nlogncode(){
    //cout<<111;
    int b[500005];
    b[0]=0;
    for(int i=1;i<=n;i++){
        b[i]=(b[i-1] xor a[i]);
    }
    int ans=0,last=0;
    for(int i=1;i<=n;i++){
        s.insert(b[i-1]);
        auto j=lower_bound(s.begin(),s.end(),(b[i] xor k));
        if(j==s.end()){
            continue;
        }
        if(k==(b[i] xor *j)){
            ans++;
            s.clear();
        }
        /*
        for(int j=last+1;j<=i;j++){
            if((b[i] xor b[j-1])==k){
                ans++;
                last=i;
                break;
            }
        }*/
    }
    cout<<ans;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=1000){
        fangcode();
        return 0;
    }
    nlogncode();

    return 0;
}
