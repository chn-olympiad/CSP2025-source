#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e6+10;
int f[N],lst[N];
int a[N],pre[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin.tie(0);ios::sync_with_stdio(0);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];pre[i]=pre[i-1]^a[i];
    }
    memset(lst,-1,sizeof(lst));lst[0]=0;
    for(int i=1;i<=n;++i){
        f[i]=f[i-1];
        int pos=lst[k^pre[i]];
        if(pos!=-1)f[i]=max(f[i],f[pos]+1);
        // cerr<<f[i]<<' ';
        lst[pre[i]]=i;
    }cout<<f[n]<<endl;
    return 0;
}