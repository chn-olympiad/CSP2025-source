#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
#define pi pair<int,int>
#define p1 first
#define p2 second
#define m_p make_pair
#define p_b push_back
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
inline ll read(){
    ll x=0;short t=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}
int n,a[maxn][3],id[maxn],cnt[3];
void slv(){
    n=read();int res=0;up(i,0,2)cnt[i]=0;
    up(i,1,n){
        up(j,0,2)a[i][j]=read();
        int p=max_element(a[i],a[i]+3)-a[i];
        id[i]=p,res+=a[i][p],cnt[p]++;
    }
    if(cnt[0]>n/2||cnt[1]>n/2||cnt[2]>n/2){
        vector<int>S;
        up(i,1,n)if(cnt[id[i]]>n/2){
            int mx=1e9;
            up(k,0,2)if(k^id[i])mx=min(mx,a[i][id[i]]-a[i][k]);
            S.p_b(mx);
        }
        sort(S.begin(),S.end());
        int d=(int)S.size()-n/2;
        up(i,0,d-1)res-=S[i];
    }
    printf("%d\n",res);
}
int main(){
    freopen("club.in","r",stdin),freopen("club.out","w",stdout);
    int t=read();while(t--)slv();
    return 0;
}