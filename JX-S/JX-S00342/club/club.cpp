#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL in(){
    char ch;
    LL ans=0;
    ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        ans=10*ans+ch-'0';
        ch=getchar();
    }
    return ans;
}
struct node{
    LL i,w;
};
bool cmp(node a,node b){
    return a.w>b.w;
}
const LL N=100000;
LL t,n,l;
LL ans;
LL f[5];
LL cnt[5];
node b[N+5];
LL a[N+5][10];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=in();
    while(t--){
        ans=0;
        memset(cnt,0,sizeof(cnt));
        n=in();
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                a[i][j]=in();
            }
            int maxx=0,r=0;
            for(int j=0;j<3;j++){
                if(a[i][j]>=maxx){
                    maxx=a[i][j];
                    r=j;
                }
            }
            a[i][4]=r;
            maxx=0;
            for(int j=0;j<3;j++){
                if(a[i][j]>=maxx&&j!=a[i][4]){
                    maxx=a[i][j];
                    r=j;
                }
            }
            a[i][5]=r;
            a[i][6]=3-a[i][4]-a[i][5];
            r=a[i][4];
            ans+=a[i][r];
            int XXX[3]={cnt[0],cnt[1],cnt[2]};
            f[i]=r;
            cnt[0]=XXX[0];
            cnt[1]=XXX[1];
            cnt[2]=XXX[2];
            cnt[r]++;
        }
        int maxx=0,r=0;
        for(int i=0;i<3;i++){
            if(cnt[i]>=maxx){
                maxx=cnt[i];
                r=i;
            }
        }
        if(maxx<=n/2){
            cout<<ans<<'\n';
            continue;
        }
        l=0;
        for(int i=0;i<n;i++){
            if(f[i]==r){
                b[l].w=a[i][a[i][5]]-a[i][a[i][4]];
                b[l++].i=i;
            }
        }
        sort(b,b+l,cmp);
        for(int i=0;maxx-i>n/2;i++){
            ans+=b[i].w;
            LL r1=b[i].i,r2=a[r1][5];
            cnt[a[r1][4]]--;
            cnt[r2]++;
            if(cnt[r2]>n/2){
                cnt[r2]--;
                ans-=a[i][r2];
                cnt[a[r1][6]]++;
                ans+=a[i][a[r1][6]];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
