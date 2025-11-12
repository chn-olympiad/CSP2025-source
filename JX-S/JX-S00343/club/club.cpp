#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,t,a[N],b[N],c[N],s,zd;
char zt='A';
void dfs(long pos,long long ms,long long ar,long long br,long long cr){
    if(pos==n+1){
        zd=max(zd,ms);
        return;
    }
    if(ar<(n/2)) dfs(pos+1,ms+a[pos],ar+1,br,cr);
    if(br<(n/2)) dfs(pos+1,ms+b[pos],ar,br+1,cr);
    if(cr<(n/2)) dfs(pos+1,ms+c[pos],ar,br,cr+1);
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(long long i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]!=0&&c[i]!=0) zt='B';
        }
        if(zt=='A'){
            long long zd=0;
            sort(a,a+n);
            for(long long i=n;i>n/2;i--) s+=a[i];
            cout<<s<<endl;
        }
        else{
            zd=0;
            dfs(1,0,0,0,0);
            cout<<zd<<endl;
        }
    }

    return 0;
}
