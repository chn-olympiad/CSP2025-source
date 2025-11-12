#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
inline int random(int l,int r){return rnd()%(r-l+1)+l;}
int main(){
    freopen("road5.in","w",stdout);
    
    int n=10000,m=1000000,k=10;
    printf("%d %d %d\n",n,m,k);
    for(int i=1;i<n;i++)
    {
        int u=random(1,i+1),v=i,w=random(1,1e9);
        printf("%d %d %d\n",u,v,w);
    }
    for(int i=n;i<=m;i++)
    {
        int u=random(1,n),v=random(1,n),w=random(1,1e9);
        while(u==v)
            u=random(1,n),v=random(1,n);
        printf("%d %d %d\n",u,v,w);
    }
    for(int t=1;t<=k;t++)
    {
        int c=random(1,1e9);
        printf("%d ",c);
        for(int i=1;i<=n;i++)
        {
            int w=random(1,1e6);
            printf("%d ",w);
        }
        puts("");
    }

    return 0;
}