#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
using big = long long;

int a[500005],s[500005],f[1<<21],n,k;
struct node{
    int s,t;
    bool operator<(node o){
        return t<o.t;
    }
} d[500005];int cnt;
big ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    memset(f,-1,sizeof f);
    cin>>n>>k;
    f[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
        if(f[s[i]^k]!=-1) d[++cnt].s=f[s[i]^k]+1,d[cnt].t=i;
        f[s[i]]=i;
    }
    sort(d+1,d+cnt+1);
    int r=0;
    for(int i=1;i<=cnt;i++){
        if(d[i].s>r) {
            ans++;
            r=d[i].t;
        }
    }
    cout<<ans;
    return 0;
}
