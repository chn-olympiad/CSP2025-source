#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int read(){
    int res=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')res=(res<<3)+(res<<1)+(c-'0'),c=getchar();
    return res*f;
}
void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
const int maxn=2e5+5;
int n,a[maxn][3],cnt[3];
vector<int>vec[3];
void solve(){
    n=read();cnt[1]=cnt[2]=cnt[0]=0;vec[0].clear(),vec[1].clear(),vec[2].clear();
    int ans=0;
    for(int i=1;i<=n;i++){
        a[i][0]=read();a[i][1]=read();a[i][2]=read();
        if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])cnt[0]++,ans+=a[i][0],vec[0].push_back(a[i][0]-max(a[i][1],a[i][2]));
        else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])cnt[1]++,ans+=a[i][1],vec[1].push_back(a[i][1]-max(a[i][0],a[i][2]));
        else cnt[2]++,ans+=a[i][2],vec[2].push_back(a[i][2]-max(a[i][1],a[i][0]));
    }
    if(cnt[0]>n/2){
        sort(vec[0].begin(),vec[0].end());
        for(int i=0;i<cnt[0]-n/2;i++)ans-=vec[0][i];
    }else if(cnt[1]>n/2){
        sort(vec[1].begin(),vec[1].end());
        for(int i=0;i<cnt[1]-n/2;i++)ans-=vec[1][i];
    }else{
        sort(vec[2].begin(),vec[2].end());
        for(int i=0;i<cnt[2]-n/2;i++)ans-=vec[2][i];
    }
    write(ans),putchar('\n');
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--)solve();
    return 0;
}