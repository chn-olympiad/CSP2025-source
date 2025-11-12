#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],b[500005],s,h=-1,t=-1;
map<ll,ll>e;
map<ll,ll>w;
map<ll,ll>c;
map<ll,bool>op;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    e[0]++;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]^b[i-1];
        if(e[b[i-1]^a[i]^m]>0){
            c[i]=w[b[i-1]^a[i]^m]+1;
            op[i]=1;
        }
        e[b[i]]++;
        w[b[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(op[i]){
            if(c[i]<=t){
                continue;
            }
            else{
                t=i;
                s++;
            }
        }
    }
    cout<<s;
    return 0;
}
