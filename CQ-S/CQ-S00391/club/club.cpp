#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){x=0;int f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();x*=f;}
template<typename T> inline void write(T x){if(x>9)write(x/10);putchar(x%10+'0');}
const int N=1e5+10;
int T,n,a[N][3],mx[N],cmx[N],id[N],siz[3];
vector<int> v[3];
void solve(){
    read(n);
    for(int i=1;i<=n;++i){
        read(a[i][0]),read(a[i][1]),read(a[i][2]),mx[i]=cmx[i]=3;
        if(mx[i]==3||a[i][0]>a[i][mx[i]])cmx[i]=mx[i],mx[i]=0;
        else if(cmx[i]==3||a[i][0]>a[i][cmx[i]])cmx[i]=0;
        if(mx[i]==3||a[i][1]>a[i][mx[i]])cmx[i]=mx[i],mx[i]=1;
        else if(cmx[i]==3||a[i][1]>a[i][cmx[i]])cmx[i]=1;
        if(mx[i]==3||a[i][2]>a[i][mx[i]])cmx[i]=mx[i],mx[i]=2;
        else if(cmx[i]==3||a[i][2]>a[i][cmx[i]])cmx[i]=2;
    }
    for(int i=1;i<=n;++i)id[i]=i;
    sort(id+1,id+1+n,[&](int x,int y){return a[x][mx[x]]>a[y][mx[y]];});
    siz[0]=siz[1]=siz[2]=0,v[0].clear(),v[1].clear(),v[2].clear();
    int ans=0;
    for(int x=1;x<=n;++x){
        int i=id[x];
        // if(a[i][mx[i]]==a[i][cmx[i]])
        //     if(siz[mx[i]]>siz[cmx[i]])swap(mx[i],cmx[i]);
        ++siz[mx[i]],ans+=a[i][mx[i]],v[mx[i]].push_back(i);
        // else if(siz[cmx[i]]<n/2)++siz[cmx[i]],ans+=a[i][cmx[i]];
    }
    if(max({siz[0],siz[1],siz[2]})<=n/2)return write(ans),putchar('\n'),void();
    int op=0;
    if(siz[1]>siz[op])op=1;
    if(siz[2]>siz[op])op=2;
    sort(v[op].begin(),v[op].end(),[&](int x,int y){return a[x][mx[x]]-a[x][cmx[x]]>a[y][mx[y]]-a[y][cmx[y]];});
    while(siz[op]>n/2){
        int x=v[op].back();v[op].pop_back();
        // cout<<"??"<<x<<" "<<op<<" "<<mx[x]<<" "<<cmx[x]<<"\n";
        ans-=a[x][mx[x]]-a[x][cmx[x]],--siz[op];
    }
    write(ans),putchar('\n');
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    read(T);
    while(T--)solve();
    return 0;
}