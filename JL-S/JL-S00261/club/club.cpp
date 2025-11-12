#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q[5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,n,ans; scanf("%d",&T);
    while(T--){
        scanf("%d",&n),ans=0;
        for(int i=1,a,b,c,tmp;i<=n;i++){
            scanf("%d%d%d",&a,&b,&c),tmp=max(a,max(b,c));
            if(tmp==a) q[1].push(a-max(b,c)),ans+=a;
            else if(tmp==b) q[2].push(b-max(a,c)),ans+=b;
            else if(tmp==c) q[3].push(c-max(a,b)),ans+=c;
        }
        for(int i=1;i<=3;i++) while(q[i].size()*2>n) ans-=q[i].top(),q[i].pop();
        printf("%d\n",ans);
        for(int i=1;i<=3;i++) while(!q[i].empty()) q[i].pop();
    }
    return 0;
}
//g++ -Wall -std=c++14 -O2 -fsanitize=address,undefined club.cpp -o club 