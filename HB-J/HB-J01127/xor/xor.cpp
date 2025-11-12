#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int w[51],v[51];
int ans,n,k,a[N];
int yh(int a,int b){
    int ws=0,vs=0;
    for(int i=1;i<=50;i++){
        w[i]=0;
        v[i]=0;
    }
    while(a){
        w[++ws]=a%2;
        a/=2;
    }
    while(b){
        v[++vs]=b%2;
        b/=2;
    }
    for(int i=max(ws,vs);i>=1;i--){
        if(w[i]!=v[i]){
            w[i]=1;
        }else{
            w[i]=0;
        }
    }
    int bs=1,sum=0;
    for(int i=1;i<=max(ws,vs);i++){
        sum+=w[i]*bs;
        bs*=2;
    }
    return sum;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int z=0;
    for(int i=1;i<=n;i++){
        z=yh(z,a[i]);
        if(z==k){
            z=0;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
