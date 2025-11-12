#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;
const int N=1e5+10;

int n,Ans,a[N][3];
priority_queue<PII,vector<PII>,greater<PII>> q[3];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d",&n); Ans=0;
        for(int i=1;i<=n;++i)
            for(int j=0;j<3;++j)
                scanf("%d",&a[i][j]);
        for(int i=0;i<3;++i) while(q[i].size()) q[i].pop();
        for(int i=1;i<=n;++i){
            int t=0;
            if(a[i][1]>a[i][t]) t=1;
            if(a[i][2]>a[i][t]) t=2;
            int r=-1;
            for(int j=0;j<3;++j)
                if(j!=t && (r==-1 || a[i][j]>a[i][r])) r=j;
            if(q[t].size()<n/2){
                q[t].push({a[i][t]-a[i][r],r});
                Ans+=a[i][t];
            }
            else{
                PII x=q[t].top();
                if(a[i][t]-a[i][r]>x.first){
                    q[t].pop();
                    q[t].push({a[i][t]-a[i][r],r});
                    Ans+=a[i][t]-x.first;
                }
                else{
                    Ans+=a[i][r];
                }
            }
        }
        printf("%d\n",Ans);
    }
    return 0;
}