#include<bits/stdc++.h>
using namespace std;
struct node
    {
        int a,b;
    };
node vis[111]={};
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);
    int n,m;
    cin>>n>>m;
    int N=n*m;
    int ans=0;
    for(int i=1; i<=N; ++i)
    {
        int qp;
        cin>>qp;
        vis[i].a=qp;
        vis[i].b=i;
    }
    for(int i=1; i<=N; ++i)
    {
        for(int l=1; l<=N-i; ++l)
        {
            int qq=0;
            if(vis[l].a<vis[l+1].a)
            {
                qq=vis[l].a;
                vis[l].a=vis[l+1].a;
                vis[l+1].a=qq;
            }
        }
    }
    for(int i=1; i<=N; ++i)
        if(vis[i].b==1)ans=i,break;
        int l=ans/n,h=0;
        if(ans%n!=0) l++;
        if(ans%n==0&&l%2==0) h=1;
        if(ans%n==0&&l%2!=0) h=m;
        if(ans%n!=0&&l%2==0) h=m-(ans%n);
        if(ans%n!=0&&l%2!=0) h=ans%n;
    fclose(stdin);
    fclose(stdout);
}
