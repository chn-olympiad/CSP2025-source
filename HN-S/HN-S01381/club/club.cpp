#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010,inf=1e18;

inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

int t,n,a[N][4],maxn[N],cnt[10];

bool cmp(int a,int b){
    return a>b;
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    t=read();
    while(t--){
        n=read();
        int res=0;
        memset(cnt,0,sizeof cnt);
        for(int i=1;i<=n;i++){
            a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
            maxn[i]=max({a[i][1],a[i][2],a[i][3]});
            maxn[i]=0;
            a[i][0]=-1;
            if(a[i][1]>a[i][maxn[i]])maxn[i]=1;
            if(a[i][2]>a[i][maxn[i]])maxn[i]=2;
            if(a[i][3]>a[i][maxn[i]])maxn[i]=3;
            cnt[maxn[i]]++;
            res+=a[i][maxn[i]];
        }
        vector<int> v;
        v.clear();
        for(int i=1;i<=3;i++){
            if(cnt[i]>n/2){
                for(int j=1;j<=n;j++){
                    if(maxn[j]==i){
                        int minn=inf;
                        for(int k=1;k<=3;k++){
                            if(k==i)continue;
                            minn=min(minn,a[j][i]-a[j][k]);
                        }
                        v.push_back(minn);
                    }
                }
                sort(v.begin(),v.end(),cmp);
                while(cnt[i]>n/2){
                    res-=v.back();
                    v.pop_back();
                    cnt[i]--;
                }
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}