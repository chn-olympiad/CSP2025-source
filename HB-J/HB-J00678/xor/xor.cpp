#include <bits/stdc++.h>
using namespace std;
const int N=600010;
int n,k,a[N],s[N],f[N],ans,maxn[N],lst[2000001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    memset(lst,-1,sizeof(lst));
    lst[k]=0;
    for(int i=1;i<=n;i++){
        if(lst[s[i]]!=-1)f[i]=maxn[lst[s[i]]]+1;
        maxn[i]=max(maxn[i-1],f[i]);
        lst[(k^s[i])]=i;
    }
    cout<<maxn[n];
    return 0;
}