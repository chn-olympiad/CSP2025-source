#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=100010;
typedef long long ll;

int T,n;
ll a[MAXN][3];
ll f[210][210];
ll g[210][210];
ll tmp[MAXN];
int idx[MAXN];


int calc(int num){
    return abs(a[num][1]-a[num][2])+abs(a[num][1]-a[num][3])+abs(a[num][2]-a[num][3]);
}

int add(int num){
    return a[num][1]+a[num][2]+a[num][3];
}

int maxn(int num){
    return max(max(a[num][1],a[num][2]),a[num][3]);
}

bool cmp(int n1,int n2){
    if(calc(n1)!=calc(n2)) return calc(n1)>calc(n2);
    if(maxn(n1)!=maxn(n2)) return maxn(n1)>maxn(n2);
    return add(n1)>add(n2);
}

int nowm,nowid;
int gm,gid;
int tm,tid;
void found(int x){
    nowm=nowid=-1;
    gm=gid=-1;
    tm=tid=-1;
    for(int i=1;i<=3;i++){
        if(a[x][i]>nowm){
            nowm=a[x][i];
            nowid=i;
        }
    }
    for(int i=1;i<=3;i++){
        if(i==nowid) continue;
        if(a[x][i]>gm){
            gm=a[x][i];
            gid=i;
        }
    }
    for(int i=1;i<=3;i++){
        if(i==nowid||i==gid) continue;
        tm=a[x][i],tid=i;
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>T;
    while(T--){
        cin>>n;
        bool A=true;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0||a[i][3]!=0) A=false;
        }
        if(n<=200){
            memset(f,0,sizeof(f));
            memset(g,0,sizeof(g));
            for(int i=1;i<=n;i++){
                for(int j=0;j<=n;j++){
                    for(int k=0;k<=n;k++){
                        if(j+k>i) continue;
                        int ta=0,tb=0,tc=0;
                        if(j>=1) ta=g[j-1][k]+a[i][1];
                        if(k>=1) tb=g[j][k-1]+a[i][2];
                        if(i-j-k>=1) tc=g[j][k]+a[i][3];
                        f[j][k]=max(ta,max(tb,tc));
                    }
                }
                for(int j=0;j<=n;j++){
                    for(int k=0;k<=n;k++){
                        g[j][k]=f[j][k];
                    }
                }
            }
            ll ans=0;
            for(int i=1;i<=n/2;i++){
                for(int j=1;j<=n/2;j++){
                    if(i+j<n/2) continue;
                    ans=max(ans,f[i][j]);
                }
            }
            cout<<ans<<endl;
        } else if(A){
            for(int i=1;i<=n;i++){
                tmp[i]=a[i][1];
            }
            sort(tmp+1,tmp+1+n);
            ll ans=0;
            for(int i=n;i>=n/2+1;i--) ans+=tmp[i];
            cout<<ans<<endl;
        } else {
            for(int i=1;i<=n;i++) idx[i]=i;
            sort(idx+1,idx+1+n,cmp);
            int has[5]={0};
            ll ans=0;
            for(int kkk=1;kkk<=n;kkk++){
                int i=idx[kkk];
                found(i);
                if(has[nowid]<n/2){
                    has[nowid]++;
                    ans=ans+nowm;
                } else if(has[gid]<n/2){
                    has[gid]++;
                    ans=ans+gm;
                } else {
                    has[tid]++;
                    ans=ans+tm;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
