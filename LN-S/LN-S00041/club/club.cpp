#include<bits/stdc++.h>
using namespace std;
struct aaa{
    int q,w,e,n,s,maxn;
}a[100100];
bool cmp(aaa x,aaa y){
    return x.s>y.s;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].q>>a[i].w>>a[i].e;
            if(a[i].e>=0&&a[i].q==0)a[i].q=a[i].e;
            else if(a[i].e>=0&&a[i].w==0)a[i].w=a[i].e;
            a[i].s=a[i].q-a[i].w;
        }
        sort(a+1,a+1+n,cmp);
        int ans=0;
        for(int i=1;i<=n/2;i++){
            ans+=a[i].q;
        }
        for(int i=n/2+1;i<=n;i++){
            ans+=a[i].w;
        }
        cout<<ans<<endl;
    }
    return 0;
}
