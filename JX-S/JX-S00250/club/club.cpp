#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,inf=2e4+10;
int T,n,ans;
int tmp[4][N],cnt[4];
struct node{
    int a[4],maxn,minn,mid;
    int cha;
}s[N];
bool cmp(int x,int y){
    return s[x].cha>s[y].cha;
}
void init(){
    memset(tmp,0,sizeof(tmp));
    memset(cnt,0,sizeof(cnt));
    ans=0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        init();
        cin>>n;
        for(int i=1;i<=n;i++){
            int mi=inf,ma=0;
            for(int j=1;j<=3;j++){
                cin>>s[i].a[j];
                if(s[i].a[j]>ma) ma=s[i].a[j],s[i].maxn=j;
                if(s[i].a[j]<mi) mi=s[i].a[j],s[i].minn=j;
            }
            for(int j=1;j<=3;j++)
                if(s[i].maxn!=j&&s[i].minn!=j)
                    s[i].mid=j,s[i].cha=s[i].a[s[i].maxn]-s[i].a[j];
            int res=s[i].maxn;
            tmp[res][++cnt[res]]=i,ans+=s[i].a[s[i].maxn];
        }
        for(int i=1;i<=3;i++){
            if(cnt[i]<=n/2) continue;
            sort(tmp[i]+1,tmp[i]+cnt[i]+1,cmp);
            while(cnt[i]>n/2){
                int now=tmp[i][cnt[i]];
                ans-=s[now].cha;
                cnt[i]--;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
