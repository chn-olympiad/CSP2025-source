#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int n,k,a[N],ans;
bool flagA=1,flagB=1;

int seg[4*N];

int build(int u,int l,int r){
    if(l==r){
        seg[u]=a[l];
        return seg[u];
    }
    int mid=(l+r)>>1;
    seg[u]=build(2*u,l,mid)^build(2*u+1,mid+1,r);
    return seg[u];
}

bool InRange(int l,int r,int L,int R){
    return (l>=L)&&(r<=R);
}
bool OutOfRange(int l,int r,int L,int R){
    return (r<L)||(l>R);
}

int query(int u,int l,int r,int L,int R){
    // cerr<<u<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<":"<<seg[u]<<endl;
    if(InRange(l,r,L,R)){
        return seg[u];
    }else if(!OutOfRange(l,r,L,R)){
        int mid=(l+r)>>1;
        return query(2*u,l,mid,L,R)^query(2*u+1,mid+1,r,L,R);
    }else{
        return 0;
    }
}

struct node{
    int l,r,len;
};

struct cmp{
    bool operator() (node x,node y){
        return x.len>y.len;
    }
};

priority_queue<node,vector<node>,cmp>pq;

bool flag[4*N];
bool lz[4*N];

bool queryflag(int u,int l,int r,int L,int R){
    // if(L==781&&R==787)cerr<<u<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<":QUERY "<<flag[u]<<" "<<lz[u]<<endl;
    // cerr<<u<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<":"<<flag[u]<<endl;
    if(InRange(l,r,L,R)){
        flag[u]=max(flag[u],lz[u]);
        return flag[u];
    }else if(!OutOfRange(l,r,L,R)){
    // if(L==781&&R==787)cerr<<u<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<":QUERY OutOfRange "<<flag[u]<<" "<<lz[u]<<endl;
        lz[2*u]=max(lz[u],lz[2*u]);
        lz[2*u+1]=max(lz[u],lz[2*u+1]);
        // lz[u]=0;
        int mid=(l+r)>>1;
        return queryflag(2*u,l,mid,L,R)||queryflag(2*u+1,mid+1,r,L,R);
    }else{
        return 0;
    }
}

void modify(int u,int l,int r,int L,int R,bool x){
    // if(L==787&&R==790)cerr<<u<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<":MODIFY"<<endl;
    if(InRange(l,r,L,R)){
        flag[u]=x;
        lz[u]=x;
        // if(L==787&&R==790)cerr<<u<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<":MODIFY InRANGE "<<flag[u]<<" "<<lz[u]<<endl;
        return;
    }else if(!OutOfRange(l,r,L,R)){
        // if(L==787&&R==790)cerr<<u<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<":MODIFY OUTOFRANGE"<<endl;
        flag[u]=x;
        // lz[u]=x;
        // cerr<<u<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<"MODIFY"<<endl;
        int mid=(l+r)>>1;
        modify(2*u,l,mid,L,R,x);
        modify(2*u+1,mid+1,r,L,R,x);
    }else{
        return;
    }
}

signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k){
        flagA=0;
    }
    if(k>1){
        flagB=0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            flagA=0;
        }
        if(a[i]>1){
            flagB=0;
        }
    }
    if(flagA){
        cout<<(n-n%2)/2<<endl;
        fclose(stdin);fclose(stdout);
        return 0;
    }
    if(flagB){
        if(k==0){
            for(int i=1;i<=n;i++){
                // cerr<<i<<" "<<a[i]<<" "<<a[i-1]<<":"<<ans<<endl;
                if(a[i]==0){
                    ans++;
                }
                if(a[i]==1&&a[i-1]==1){
                    a[i]=0;
                    ans++;
                }
            }
        }else{
            for(int i=1;i<=n;i++){
                // cerr<<i<<" "<<a[i]<<" "<<a[i-1]<<":"<<ans<<endl;
                if(a[i]==1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
        fclose(stdin);fclose(stdout);
        return 0;
    }
    build(1,1,n);
    // for(int i=1;i<=pow(2,n-1)-1;i++){
    //     cerr<<seg[i]<<" ";
    // }
    // cerr<<endl<<endl;
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            int tmp=query(1,1,n,l,r);
            // cerr<<l<<" "<<r<<":"<<ans<<" "<<tmp<<endl;
            if(tmp==k){
                // cerr<<l<<" "<<r<<endl;
                // ans++;
                // l=r;
                pq.push({l,r,r-l+1});
            }
        }
    }
    while(!pq.empty()){
        node cur=pq.top();pq.pop();
        // cerr<<cur.l<<" "<<cur.r<<" "<<cur.len<<endl;
        // for(int i=1;i<=pow(2,n-1)-1;i++){
        //     cerr<<flag[i]<<" ";
        // }
        // cerr<<endl;
        int tmp=queryflag(1,1,n,cur.l,cur.r);
        if(!tmp){
            // cerr<<cur.l<<" "<<cur.r<<endl;
            modify(1,1,n,cur.l,cur.r,1);
            ans++;
        }
        // cerr<<tmp<<endl<<endl;
    }
    cout<<ans<<endl;
    fclose(stdin);fclose(stdout);
    return 0;
}