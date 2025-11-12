#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
#define maxm 1000005
#define ll long long
#define frp freopen
#define  fio(in,out) frp(in,"r",stdin),frp(out,"w",stdout)
void bug(){cout<<endl;}
template<typename T,typename ... Ts>
void bug(T x,Ts ... y){cout<<x<<" ",bug(y...);}
template<typename T=int>
T read(){
    T res=0,f=1;char c;
    for(;(c=getchar())<'0'||c>'9';c=='-'?f=-f:0);
    while(c>='0'&&c<='9')res=(res<<3)+(res<<1)+c-'0',c=getchar();
    return res*f;
}
#define ull unsigned ll
const int base=27;
int n,q;
ull sum[maxn][2],pre[maxm],qp[maxm],S,ans;
string s[maxn][2],c[2];
ull cal(int l,int r){
    if(l>r)return 0;
    return pre[r]-(l?pre[l-1]:0)*qp[r-l+1];
}
int main(){
    int i,j;
    fio("replace.in","replace.out");
    n=read(),q=read();
    for(i=1;i<=n;++i){
        cin>>s[i][0]>>s[i][1];
        for(j=0;j<s[i][0].size();++j){
            sum[i][0]=sum[i][0]*base+s[i][0][j]-'a'+1;
            sum[i][1]=sum[i][1]*base+s[i][1][j]-'a'+1;
        }
    }
    qp[0]=1;
    for(i=1;i<=1e6;++i)qp[i]=qp[i-1]*base;
    while(q--)
    {
        cin>>c[0]>>c[1];S=0;
        pre[0]=c[0][0]-'a'+1;
        for(i=1;i<c[0].size();++i){
            pre[i]=pre[i-1]*base+c[0][i]-'a'+1;
            S=S*base+c[1][i]-'a'+1;
        }ans=0;
        for(i=0;i<c[0].size();++i)
        {
            for(j=1;j<=n;++j)if(i+1+s[j][0].size()<=c[0].size())
            {
                int sz=s[j][0].size();
                if(cal(i,i+sz-1)==sum[j][0]){
                if(cal(0,i-1)*qp[c[0].size()-i-1]+qp[c[0].size()-1-(i+sz)]*sum[j][1]+cal(i+sz,c[0].size()-1)==S)
                    ++ans;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}