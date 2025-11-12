#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int n,x[500005],cnt,ans,mina,minb;
ll k;
struct node{
    int a,b;
}f[500005];
bool cmp(node a,node b){
    return a.b<b.b;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        ll tmp;
        cin>>tmp;
        x[i]=x[i-1]^tmp;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if((x[j]^x[i])==k){
                cnt++;
                f[cnt].a=i+1;
                f[cnt].b=j;
                break;
            }
        }
    }
    if((x[n]^x[n-1])==k){
        cnt++;
        f[cnt].a=n;
        f[cnt].b=n;
    }
    sort(f+1,f+cnt+1,cmp);
    mina=f[1].a;
    minb=f[1].b;
    ans=1;
    for(int i=1;i<=cnt;i++){
        if(f[i].a>minb){
            mina=f[i].a;
            minb=f[i].b;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
