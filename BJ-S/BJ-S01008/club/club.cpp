#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fr first
#define sc second
#define mk make_pair
#define pb push_back
const int MAXN=100010;
int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();return x*f;}
int n,ct[3];
pii a[MAXN][3];
vector<int>st[3];
void slv(){
    n=read();
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++)a[i][j]={read(),j};
        sort(a[i],a[i]+3);
        ct[a[i][2].sc]+=a[i][2].fr;
        st[a[i][2].sc].pb(a[i][1].fr-a[i][2].fr);
    }
    for(int i=0;i<3;i++)sort(st[i].begin(),st[i].end());
    for(int i=0;i<3;i++){
        while(st[i].size()>n/2){
            ct[i]+=st[i].back();
            st[i].pop_back();
        }
    }
    printf("%lld\n",ct[0]+ct[1]+ct[2]);
    ct[0]=ct[1]=ct[2]=0;
    st[0].clear();
    st[1].clear();
    st[2].clear();

}
signed main(){
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    int _=read();while(_--)
    slv();
    return 0;
}