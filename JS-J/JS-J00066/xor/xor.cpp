#include<bits/stdc++.h>
using namespace std;
int a[500000+5];
int js[500000+5];
int n,k,ans,tag_A=1;
set<int > s;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k!=1)tag_A=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        js[i]=js[i-1]^a[i];
        if(a[i]!=1)tag_A=0;
    }
    if(tag_A){cout<<n/2;return 0;}
    s.insert(0);
    for(int i=1;i<=n;i++){
        if(s.find(js[i]^k)!=s.end()||a[i]==k){
            ans++;s.clear();
            s.insert(js[i]);
        }
        else s.insert(js[i]);
    }
    cout<<ans;
    return 0;
}
