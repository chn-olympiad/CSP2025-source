#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0') {if(ch=='-') f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0') {x=(x<<3)+(x<<1)+(ch-'0');ch=getchar();}
    return x*f;
}
const int N=1e5+5;
struct stu{
    int sum,s,id,b;
    bool operator<(const stu &t) const{
        return s>t.s;
    }
}num[N*3];
int sum[10];
bool vis[N];
signed main(){
    freopen("club.in" ,"r",stdin );
    freopen("club.out","w",stdout);
    // freopen("1.in","r",stdin);
    int T=read();
    while(T--) {
        memset(vis,0,sizeof(vis));
        int n=read(),ans=0,cnt=0;
        sum[1]=sum[2]=sum[3]=n/2;
        for(int i=1;i<=n;i++) {
            int a=read(),b=read(),c=read();
            num[++cnt]=(stu){a,min(a-b,a-c),i,1};
            num[++cnt]=(stu){b,min(b-a,b-c),i,2};
            num[++cnt]=(stu){c,min(c-b,c-a),i,3};
        }
        sort(num+1,num+cnt+1);
        for(int i=1;i<=cnt;i++) if(!vis[num[i].id]&&sum[num[i].b]) {
            ans+=num[i].sum;
            vis[num[i].id]=1;
            sum[num[i].b]--;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*

写这题真是太惊险了
不知道我的贪心会不会假

*/