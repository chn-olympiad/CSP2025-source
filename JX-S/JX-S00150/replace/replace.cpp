#include<bits/stdc++.h>
using namespace std;
const int base=37,mod=1e9+7;
string s[200005][2];
int len[200005];
map<int,int>q,qq[200005],g1[200005];
int cnt,tot,kkk;
vector<int>g[200005];
int da[200005];
struct as{
    int id,xun;
    as(int aa=0,int bb=0){
        id=aa;
        xun=bb;
    }
};
vector<as>que[200005];
int son[5000005][27],sz,ov[200005];
void in(string a,int n){
    int p=0;
    for(int i=1;i<=n;i++){
        int e=a[i]-'a'+1;
        if(!son[p][e])son[p][e]=++sz;
        p=son[p][e];
    }
    ov[p]=1;
}
int dfn[200005],df,L[200005],R[200005];
void dfs(int x){
    dfn[x]=L[x]=++df;
    for(int i=1;i<=26;i++)
        if(son[x][i])
            dfs(son[x][i]);
    R[x]=df;
}
int ask(string a,int n){
    int p=0;
    for(int i=1;i<=n;i++){
        int e=a[i]-'a'+1;
        p=son[p][e];
    }
    return dfn[p];
}
int cun[200005];
string cn[200005];
string asa[200005],asb[200005];
struct tree{
    int ans,la;
}T[800005];
void pushdown(int d){
T[d*2].ans+=T[d].la,T[d*2].la+=T[d].la;
T[d*2+1].ans+=T[d].la,T[d*2+1].la+=T[d].la;
T[d].la=0;
}
void add(int d,int l,int r,int ll,int rr,int z){
    if(ll>rr)return;
    if(ll<=l&&r<=rr)
    {
        T[d].ans+=z;
        T[d].la+=z;
        return;
    }pushdown(d);
    int mid=(l+r)/2;
    if(ll<=mid)add(d*2,l,mid,ll,rr,z);
    if(rr>mid)add(d*2+1,mid+1,r,ll,rr,z);
    T[d].ans=T[d*2].ans+T[d*2+1].ans;
}
int ask(int d,int l,int r,int k){
    if(l==r)
    {return T[d].ans;
    }
    int mid=(l+r)/2;
    pushdown(d);
    if(k<=mid)return ask(d*2,l,mid,k);
    return ask(d*2+1,mid+1,r,k);
}
int main(){
        freopen("replace1.in","r",stdin);
    int n,Q;
    cin>>n>>Q;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
        len[i]=s[i][1].size();
        s[i][1]=" "+s[i][1];
        s[i][2]=" "+s[i][2];
        int m=len[i];
        int l=0,r=m+1;
        for(int j=1;j<=m;j++)
            if(s[i][1][j]!=s[i][2][j])break;
            else l=j;
        for(int j=m;j>=1;j--)
            if(s[i][1][j]!=s[i][2][j])break;
            else r=j;
        int ha1=0,ha2=0;
        for(int j=l+1;j<=r-1;j++)
            ha1=(1LL*ha1*base+s[i][1][j]-'a'+1)%mod,
            ha2=(1LL*ha2*base+s[i][2][j]-'a'+1)%mod;
        if(!q[ha1])q[ha1]=++cnt;
        if(!q[ha2])q[ha2]=++cnt;
        int z=qq[q[ha1]][q[ha2]];
        if(!qq[q[ha1]][q[ha2]])
            qq[q[ha1]][q[ha2]]=z=++tot;
        ha1=0;
        for(int j=1;j<=l;j++)ha1=(1LL*ha1*base+s[i][1][j]-'a'+1)%mod;
        if(!g1[z][ha1])g1[z][ha1]=++kkk;
        string now=" ";
        for(int j=r;j<=m;j++)now+=s[i][1][j];
        cun[i]=g1[z][ha1];
        cn[i]=now;
        in(now,now.size()-1);
    }
    for(int i=1;i<=Q;i++){
        string a,b;
        cin>>a>>b;
        asa[i]=a,asb[i]=b;
        if(a.size()!=b.size())continue;
        int m=a.size();
        a=" "+a;
        b=" "+b;
        int l=0,r=m+1;
        for(int j=1;j<=m;j++)
            if(a[j]!=b[j])break;
            else l=j;
        for(int j=m;j>=1;j--)
            if(a[j]!=b[j])break;
            else r=j;
        int ha1=0,ha2=0;
        for(int j=l+1;j<=r-1;j++)
            ha1=(1LL*ha1*base%mod+a[j]-'a'+1)%mod,
            ha2=(1LL*ha2*base%mod+b[j]-'a'+1)%mod;
        if(!q[ha1]||!q[ha2])
        continue;
        int z1=q[ha1],z2=q[ha2];
        if(!z1||!qq[z1].size()||!z2)continue;
        if(!qq[q[ha1]][q[ha2]])continue;
        int z=qq[q[ha1]][q[ha2]];
        string now=" ";
        for(int j=r;j<=m;j++)now+=a[j];
        in(now,now.size()-1);
    }
    dfs(0);
    for(int i=1;i<=Q;i++){
        string a,b;
        a=asa[i],b=asb[i];
        if(a.size()!=b.size())continue;
        int m=a.size();
        a=" "+a;
        b=" "+b;
        int l=0,r=m+1;
        for(int j=1;j<=m;j++)
            if(a[j]!=b[j])break;
            else l=j;
        for(int j=m;j>=1;j--)
            if(a[j]!=b[j])break;
            else r=j;
        int ha1=0,ha2=0;
        for(int j=l+1;j<=r-1;j++)
            ha1=(1LL*ha1*base+a[j]-'a'+1)%mod,
            ha2=(1LL*ha2*base+b[j]-'a'+1)%mod;
        if(!q[ha1]||!q[ha2])continue;
        int z1=q[ha1],z2=q[ha2];
        if(!qq[z1].size())continue;
        if(!qq[q[ha1]][q[ha2]])continue;
        int z=qq[q[ha1]][q[ha2]];
        asa[i]=a,asb[i]=b;
        string now=" ";
        for(int j=r;j<=m;j++)now+=a[j];
        int xun=ask(now,now.size()-1);
        ha1=0;
        for(int j=1;j<=l;j++){
            ha1=(1LL*ha1*base+a[j]-'a'+1)%mod;
            if(g1[z][ha1])
                que[g1[z][ha1]].push_back(as(i,xun));
        }
    }
     for(int i=1;i<=n;i++){
            string now=cn[i];
        int xun=ask(now,now.size()-1);
        g[cun[i]].push_back(xun);
    }
    for(int i=1;i<=tot;i++){
        for(auto x:g1[i]){
            int zz=x.second;
            for(int p:g[zz])
            {cout<<zz<<" "<<L[p]<<" "<<R[p]<<" "<<df<<endl;
            add(1,0,df,L[p],R[p],1);
            }
            for(auto p:que[zz])
            {cout<<zz<<" "<<p.xun<<"sb"<<" "<<p.id<<endl;cout<<ask(1,0,df,p.xun)<<endl;da[p.id]+=ask(1,0,df,p.xun);}

            for(int p:g[zz])add(1,0,df,L[p],R[p],-1);
        }
    }
    for(int i=1;i<=Q;i++)cout<<da[i]<<"\n";
}
