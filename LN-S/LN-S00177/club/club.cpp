#include <bits/stdc++.h>
using namespace std;
int  ans=0;
int d[202],n[202],m[202];
int   b,sum;
int dfs(int w,int r,int x,int y){
    if(w==b){
        ans=max(sum,ans);
        return 0;
    }
    if(r==b/2){
        sum+=n[w+1];
        dfs(w+1,r,x+1,y);
        sum-=n[w+1];
        sum+=m[w+1];
        dfs(w+1,r,x,y+1);
        sum-=m[w+1];
    }else if(x==b/2){
        sum+=d[w+1];
        dfs(w+1,r+1,x,y);
        sum-=d[w+1];
        sum+=m[w+1];
        dfs(w+1,r,x,y+1);
        sum-=m[w+1];
    }else if(y==b/2){
        sum+=n[w+1];
        dfs(w+1,r,x+1,y);
        sum-=n[w+1];
        sum+=d[w+1];
        dfs(w+1,r+1,x,y);
        sum-=d[w+1];
    }
    else{
        sum+=n[w+1];
        dfs(w+1,r,x+1,y);
        sum-=n[w+1];
        sum+=d[w+1];
        dfs(w+1,r+1,x,y);
        sum-=d[w+1];
        sum+=m[w+1];
        dfs(w+1,r,x,y+1);
        sum-=m[w+1];
    }
    return 0;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int a;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b;
        int g=0;
        for(int j=1;j<=b;j++){
            cin>>d[j]>>n[j]>>m[j];
            if(n[j]==0&&m[j]==0){
                g++;
            }
        }
        if(g==b){
            sort(d+1,d+a+1);
            for(int i=b;i>=a/2;i--){
                ans+=d[i];
            }
        }else if(b>200){
            for(int j=1;j<=b;j++){
                int f=max(d[j],n[j]);
                ans+=max(f,m[j]);
            }
        }else{
            sum+=d[1];
            dfs(1,1,0,0);
            sum=sum-d[1]+n[1];
            dfs(1,0,1,0);
            sum=sum-n[1]+m[1];
            dfs(1,0,0,1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
