#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005];
int xr(int a,int b){
    int ans=0,v=0;
    if(a>b) swap(a,b);
    while(a&&b){
        if((a&1)!=(b&1)) ans+=1<<v;
        v++,a>>=1,b>>=1;
    }
    ans+=b<<v;
    return ans;
}
int fd(int l,int r){
    int ans=0,lst=r;
    if(s[l]==r) return 1;
    for(int i=l;i<=lst;i++)
        if(s[i]!=-1)
            ans=max(ans,fd(s[i]+1,r)+1),lst=min(lst,s[i]);
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    memset(s,-1,sizeof s);
    for(int l=1,m=0;l<=n;l++,m=0){
        for(int r=l;r<=n;r++){
            m=xr(m,a[r]);
            if(m==k){
                s[l]=r;
                break;
            }
        }
    }
    cout<<fd(1,n);
    return 0;
}
