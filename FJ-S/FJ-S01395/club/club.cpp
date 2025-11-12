#include<bits/stdc++.h>
constexpr int rSiz=1<<21;
char rBuf[rSiz],*p1=rBuf,*p2=rBuf;
#define gc() (p1==p2&&(p2=(p1=rBuf)+fread(rBuf,1,rSiz,stdin),p1==p2)?EOF:*p1++)
template<class T>void rd(T&x){
    char ch=gc();
    for(;ch<'0'||ch>'9';ch=gc());
    for(x=0;ch>='0'&&ch<='9';ch=gc())
        x=(x<<1)+(x<<3)+(ch^48);
}
constexpr int _=3e5+5;
int n,a[_][3],c[3];bool d[_];
std::pair<int,int>b[_][3];
std::priority_queue<std::pair<int,int> >q;
long long ans;
void solve(){
    rd(n);
    for(;!q.empty();q.pop());
    c[0]=c[1]=c[2]=0;
    ans=0;
    for(int i=1;i<=n;++i){
        d[i]=0;
        for(int j=0;j<3;++j)rd(a[i][j]),b[i][j]={a[i][j],j};
        std::sort(b[i],b[i]+3);
        ans+=b[i][2].first;++c[b[i][2].second];
    }
    for(int p=0;p<3;++p)if(c[p]>n/2){
        for(int i=1;i<=n;++i)if(b[i][2].second==p)
            q.push({b[i][1].first-b[i][2].first,i});
        for(int i=c[p]-n/2;i;--i){
            ans+=q.top().first;q.pop();
        }
    }
    printf("%lld\n",ans);
}
#define fio(x) freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);
int main(){
    fio("club");
    int T;rd(T);
    for(;T;--T)solve();
}