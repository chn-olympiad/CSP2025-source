#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
int a[3][100005];
struct p{
    int diff;
    friend bool operator<(p x,p y){
        return x.diff>y.diff;
    }
};
int diff(int a,int b,int c){
    int s[3];
    s[0]=a;s[1]=b;s[2]=c;
    sort(s,s+2);
    return s[2]-s[1];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int x=1;x<=t;x++){
        memset(a,0,sizeof(a));
        int n=0;
        long long ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&a[0][i],&a[1][i],&a[2][i]);
        }
        vector<int>g[3];
        for(int i=1;i<=n;i++){
            int m=max(a[0][i],max(a[1][i],a[2][i]));
            ans+=m;
            int cur=0;
            if(a[0][i]==m)cur=0;
            else if(a[1][i]==m)cur=1;
            else cur=2;
            g[cur].push_back(i);
        }
        int out=0;
        if(g[0].size()>n/2)out=1;
        if(g[1].size()>n/2)out=2;
        if(g[2].size()>n/2)out=3;
        int difs[100005]={0};int l=0;
        for(int i=1;i<=n;i++){
            difs[i]=diff(a[0][i],a[1][i],a[2][i]);
        }
        if(out!=0){
            vector<long long>dis;
            priority_queue<int,vector<int>,greater<int>>p;
            int res=g[out].size()-n/2;
            for(int i=1;i<=n;i++){
                if(a[out][i]==max(a[0][i],max(a[1][i],a[2][i]))){
                    p.push(diff(a[0][i],a[1][i],a[2][i]));
                }
            }
            while(res>0){
                res--;
                ans-=p.top();
                p.pop();
            }
        }
        cout<<ans<<"\n";
    }
}