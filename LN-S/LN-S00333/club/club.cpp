#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,d[N][3],p[N],pos,c0,c1,c2,cnt,ans;
int t[10];
priority_queue<int>q;
int read(){
    int k=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
        k=k*10+ch-'0',ch=getchar();
    return k*f;
}
void insert(int x){
    if(p[x]==0){
        if(d[x][1]>d[x][2])
            q.push(d[x][1]-d[x][0]);
        else
            q.push(d[x][2]-d[x][0]);
    }
    else if(p[x]==1){
        if(d[x][0]>d[x][2])
            q.push(d[x][0]-d[x][1]);
        else
            q.push(d[x][2]-d[x][1]);
    }
    else{
        if(d[x][0]>d[x][1])
            q.push(d[x][0]-d[x][2]);
        else
            q.push(d[x][1]-d[x][2]);
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++)
            d[i][0]=read(),d[i][1]=read(),d[i][2]=read();
        ans=0,pos=-1,c0=0,c1=0,c2=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(d[i][0]>=d[i][1]&&d[i][0]>=d[i][2])
                p[i]=0,c0++;
            else if(d[i][1]>=d[i][2])
                p[i]=1,c1++;
            else
                p[i]=2,c2++;
        }
        if(c0>n/2)
            pos=0;
        if(c1>n/2)
            pos=1;
        if(c2>n/2)
            pos=2;
        for(int i=1;i<=n;i++){
            if(p[i]!=pos)
                ans+=d[i][p[i]];
            else{
                if(cnt<n/2){
                    ans+=d[i][p[i]],cnt++;
                    insert(i);
                }
                else{
                    t[0]=d[i][0],t[1]=d[i][1],t[2]=d[i][2],t[3]=d[i][p[i]]+q.top();
                    t[p[i]]=-1;
                    if(t[0]>=t[1]&&t[0]>=t[2]&&t[0]>=t[3])
                        ans+=d[i][0];
                    else if(t[1]>=t[2]&&t[1]>=t[3])
                        ans+=d[i][1];
                    else if(t[2]>=t[3])
                        ans+=d[i][2];
                    else{
                        ans+=d[i][p[i]]+q.top();
                        q.pop();
                        insert(i);
                    }
                }
            }
        }
        printf("%d\n",ans);
        while(!q.empty())
            q.pop();
    }
    return 0;
}