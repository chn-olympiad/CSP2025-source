#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,cnt=0;
bool vis[N];
int a[N];
pair<bool,int> XOR(int l){
    int i=l,xosu=0;
    pair<bool,int>ret;
    if(a[l]==k){
        ret.first=true;
        ret.second=i+1;
        return ret;
    }
    while(i<=n&&!vis[i]){
        vis[i]=true;
        xosu^=a[i++];
        if(xosu==k){
            ret.first=true;
            ret.second=i+1;
            return ret;
        }
    }for(int j=l+1;j<=i-1;j++){
        vis[j]=false;
    } ret.first=false;
    ret.second=l+1;
    return ret;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;){
        pair<bool,int> t=XOR(i);
        i=t.second;
        cnt+=t.first;
    }cout<<cnt;
    return 0;
}
