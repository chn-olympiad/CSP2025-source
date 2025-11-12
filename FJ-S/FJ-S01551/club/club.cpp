#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,tmp,cnt[5],flag[100010],a[100010][5];
priority_queue<pair<long long,long long> >q;
long long read(){
    long long x=0;char ac=getchar();
    while(ac<'0' || ac>'9') ac=getchar();
    while(ac>='0' && ac<='9') x=x*10+ac-'0',ac=getchar();
    return x;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--){
        n=read(),cnt[1]=cnt[2]=cnt[3]=ans=0;
        while(!q.empty()) q.pop();
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=3;j++)
                a[i][j]=read();
            if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3])
                cnt[1]++,ans+=a[i][1],flag[i]=1,
                q.push({-min(a[i][1]-a[i][2],a[i][1]-a[i][3]),1});
            else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3])
                cnt[2]++,ans+=a[i][2],flag[i]=2,
                q.push({-min(a[i][2]-a[i][1],a[i][2]-a[i][3]),2});
            else
                cnt[3]++,ans+=a[i][3],flag[i]=3,
                q.push({-min(a[i][3]-a[i][1],a[i][3]-a[i][2]),3});
        }
        while(cnt[1]>(n>>1) || cnt[2]>(n>>1) || cnt[3]>(n>>1)){
            // printf("%lld %lld\n",q.top().first,q.top().second);
            if(cnt[q.top().second]<=(n>>1)) q.pop();
            else ans+=q.top().first,cnt[q.top().second]--,q.pop();
        }
        printf("%lld\n",ans);
    }
    return 0;
}