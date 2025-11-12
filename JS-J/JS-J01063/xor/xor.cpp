#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],q,l,m,ans;
struct node{
    long long c,d;
}w[1000000];
bool cmp(node r,node t){ if(t.c==r.c) return r.d<t.d;return r.c<t.c;}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1) q++;
        if(a[i]>1) l=1;
        if(a[i]==k){
            m++;
            w[m].c=i;
            w[m].d=i;
        }
    }
    if(q==n){
        cout<<n/2;
        return 0;
    }
    if(!l){
        if(k==1) cout<<q;
        else{
            int j=n-q;
            for(int i=2;i<=n;i++){
                if(a[i]&&a[i-1]) j++,i++;
            }
            cout<<j;
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        int h=a[i];
        for(int j=i+1;j<=n;j++){
            h=h^a[j];
            if(h==k){
                m++;
                w[m].c=i,w[m].d=j;
            }
        }
    }
    if(m<=1){
        cout<<m;
        return 0;
    }
    sort(w+1,w+m+1,cmp);
    int u=1;
    for(int i=2;i<=m;i++){
        if(w[i].c<=w[1].d) u++;
        else break;
    }
    for(int i=1;i<=u;i++){
        long long ed=w[i].d,y=1;
        for(int j=i+1;j<=m;j++){
            if(w[j].c<=ed) continue;
            ed=w[j].d;
            y++;
        }
        ans=max(ans,y);
    }
    cout<<ans;
    return 0;
}
