/*
CSP-S 2025
Chengsinuo
GX-S00371
T1 club.cpp
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=100005;

int T,n,a[MAXN][3];

bool cmpa(int x[],int y[]){return x[0]>y[0];}

struct sB{
    int id,dt;
};

bool cmpB(sB x,sB y){return(x.dt>y.dt);}

int main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        int cntb0=0,cntc0=0;
        ll ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][1]==0)cntb0++;
            if(a[i][2]==0)cntc0++;
        }
        if(n==2)for(int i=0;i<3;i++)for(int j=0;j<3;j++){if(i==j)continue;ans=max(ans,(ll)(a[0][i]+a[1][j]));} // #1
        else if(n==4)for(int i=0;i<81;i++){ // #2
            int a1=i%3,b=(i/3)%3,c=(i/3/3)%3,d=i/3/3/3;
            if(a1==b&&a1==c||a1==c&&1==d||b==c&&c==d)continue;
            ans=max(ans,(ll)(a[0][a1]+a[1][b]+a[2][c]+a[3][d]));
        }
        else if(n==10){ // #3, #4
            for(int i=0;i<pow(3,10);i++){
                int tmp=i,cnt[3]={0,0,0},tans=0;
                for(int j=0;j<10;j++){
                    int t=(ll)(i/pow(3,j))%3;
                    cnt[t]++;
                    tans+=a[j][t];
                }
                if(cnt[0]>5||cnt[1]>5||cnt[2]>5)continue;
                ans=max(ans,(ll)tans);
            }
        }
        else if(cntc0=n){
            if(cntb0=n){ // special A
                priority_queue<int>q;
                for(int i=0;i<n;i++)q.push(a[i][0]);
                for(int i=0;(i+1)*2<=n;i++){ans+=q.top();q.pop();}
            }
            else{ //special B
                /*
                sB dt[MAXN];
                for(int i=0;i<n;i++){
                    dt[i].id=i,dt[i].dt=a[i][0]-a[i][1];
                }
                sort(dt,dt+n,cmpb);
                for(int i=0;(i+1)*2<=n;i++){ans+=a[dt[]}
                */
                ;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

//EW
