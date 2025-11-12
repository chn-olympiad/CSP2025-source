#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+5;
int n,m,a[N][5],s[5],del,now[N];LL ans;priority_queue<pair<int,int>> v[5];pair<int,int> c[N][5];
int read(int ans=0){
    char x;bool f=0;
    x=getchar();
    while(x>'9'||x<'0') x=='-'?f=1:0,x=getchar();
    while(x<='9'&&x>='0') ans=ans*10+x-'0',x=getchar();
    return ans*(f?-1:1);
}
int main(){//100pts(?)
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    // double t1=time(0);
    int t=read();
    while(t--){
        n=read(),ans=0,m=n/2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++) a[i][j]=read(),c[i][j]=make_pair(a[i][j],j);
            sort(c[i]+1,c[i]+1+3),del=c[i][3].first-c[i][2].first,now[i]=3,ans+=c[i][3].first;
            s[c[i][now[i]].second]++,v[c[i][now[i]].second].emplace(-del,i);
        }
        while(s[1]>m||s[2]>m||s[3]>m){
            int k;
            if(s[1]>m) k=1;
            if(s[2]>m) k=2;
            if(s[3]>m) k=3;
            int x=v[k].top().second,y=-v[k].top().first;v[k].pop();
            if(now[x]==1) continue;
            ans-=y,s[c[x][now[x]].second]--,s[c[x][--now[x]].second]++;
            if(now[x]==2) v[c[x][now[x]].second].emplace(c[x][2].first-c[x][1].first,x);
        }
        printf("%lld\n",ans);
        for(int i=1;i<=3;i++){
            s[i]=0;
            while(!v[i].empty()) v[i].pop();
        }
    }
    // printf("%.5lf",time(0)-t1);
    return 0;
}