#include<bits/stdc++.h>
struct FRE{
    FRE(std::string str){
        freopen((str+".in").data(),"r",stdin);
        freopen((str+".out").data(),"w",stdout);
    }
    ~FRE(){
        fclose(stdin);
        fclose(stdout);
    }
};
FRE open("club");
struct Node{
    int id,val;
    friend bool operator <(Node lhs,Node rhs){
        return lhs.val<rhs.val;
    }
};
const int N=1e5+6;
int n,d[N][4],T;
int in[N],t[4];
int vis[N];
std::priority_queue<Node>q;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        memset(t,0,sizeof(t));
        scanf("%d",&n);
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            int mx=0;
            scanf("%d%d%d",&d[i][1],&d[i][2],&d[i][3]);
            mx=std::max({d[i][1],d[i][2],d[i][3]});
            for(int j=1;j<=3;j++)
                if(d[i][j]==mx){t[in[i]=j]++;ans+=d[i][j];break;}
        }
        while(!q.empty()) q.pop();
        for(int i=1;i<=3;i++)
            if(t[i]>n/2)
            {
                for(int j=1;j<=n;j++)
                    for(int k=1;k<=3;k++)
                        if(in[j]==i&&i!=k) q.push({j,d[j][k]-d[j][i]});
                while(!q.empty()&&t[i]>n/2)
                {
                    Node tp=q.top();
                    while(vis[tp.id]) q.pop(),tp=q.top();
                    ans+=tp.val;
                    vis[tp.id]=1;
                    t[i]--;
                }
            }
        printf("%lld\n",ans);
    }
    return 0;
}
//g++ club.cpp -o club -std=c++14 -O2 -Wall -Wextra -static&&cp club1.in club.in&&size club&&time ./club&&diff club.out club1.ans&&code club.out
//g++ club.cpp -o club -std=c++14 -O2 -Wall -Wextra -static&&cp club2.in club.in&&size club&&time ./club&&diff club.out club2.ans&&code club.out
//g++ club.cpp -o club -std=c++14 -O2 -Wall -Wextra -static&&cp club3.in club.in&&size club&&time ./club&&diff club.out club3.ans&&code club.out
//g++ club.cpp -o club -std=c++14 -O2 -Wall -Wextra -static&&cp club4.in club.in&&size club&&time ./club&&diff club.out club4.ans&&code club.out
//g++ club.cpp -o club -std=c++14 -O2 -Wall -Wextra -static&&cp club5.in club.in&&size club&&time ./club&&diff club.out club5.ans&&code club.out