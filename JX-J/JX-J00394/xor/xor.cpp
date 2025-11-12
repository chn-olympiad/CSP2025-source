#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],v[N],s[N];
int ans;
struct nn{
    int l,r,v;
    int add;
}tr[N*4];
int ls(int p){
    return p*2;
}
int rs(int p){
    return p*2+1;
}
void up(int p){
    tr[p].v=max(tr[ls(p)].v,tr[rs(p)].v);
}
void pd(int p){
    int l=ls(p),r=rs(p);
    if(tr[p].add==1){
        tr[l].add=1;
        tr[r].add=1;
        tr[l].v=1;
        tr[r].v=1;
        tr[p].add=0;
    }
}
void in(int p,int l,int r){
    tr[p].l=l;
    tr[p].r=r;
    if(l==r)return;
    int md=(l+r)/2;
    in(ls(p),l,md);
    in(rs(p),md+1,r);
}
void add(int p,int L,int R){
    int l=tr[p].l,r=tr[p].r;
    if(L<=l&&r<=R){
        tr[p].v=1;
        tr[p].add=1;
        return ;
    }
    int md=(l+r)/2;
    if(L<=md)add(ls(p),L,R);
    if(R>md)add(rs(p),L,R);
    up(p);
}
int qey(int p,int L,int R){
    int l=tr[p].l,r=tr[p].r;
    int res=0;
    if(L<=l&&r<=R){
        return tr[p].v;
    }
    pd(p);
    int md=(l+r)/2;
    if(L<=md)res=max(res,qey(ls(p),L,R));
    if(R>md)res=max(res,qey(rs(p),L,R));
    up(p);
    return res;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    if(n<=1010){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            a[i]=(a[i]^a[i-1]);
        }
        for(int l=1;l<=n;l++){
            for(int i=l;i<=n;i++){
                int x=i-l+1,y=i;
                if(s[y]-s[x-1]==0){
                    if((a[y]^a[x-1])==k){
                        ans++;
                        v[x]++;
                        v[y+1]--;
                        for(int i=1;i<=n;i++){
                            s[i]=v[i];
                        }
                        for(int i=1;i<=n;i++){
                            s[i]=s[i]+s[i-1];
                        }
                        for(int i=1;i<=n;i++){
                            s[i]=s[i]+s[i-1];
                        }
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    in(1,1,n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        a[i]=(a[i]^a[i-1]);
    }
    for(int l=1;l<=n;l++){
        bool f=0;
        for(int i=l;i<=n;i++){
            int x=i-l+1,y=i;
            if(qey(1,x,y)==0){
                f=1;
                if((a[y]^a[x-1])==k){
                    ans++;
                    add(1,x,y);
                }
            }
        }
        if(f==0)break;
    }
    cout<<ans;
    return 0;
}
