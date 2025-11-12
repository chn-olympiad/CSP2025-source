// club
#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-f;
    for(; isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
    return f*x;
}
const int N=1e5+5;
int T,n;
int a[N][5];
int club[N];
int t[5];
int ans;
priority_queue<int,vector<int>,greater<int> >q,air;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    T=read();
    while(T--){
        ans=0;
        memset(t,0,sizeof(t));
        n=read();
        for(int i=1;i<=n;i++){
            int p=0;
            for(int j=1;j<=3;j++){
                a[i][j]=read();
                if(a[i][j]>a[i][p])p=j;
            }
            club[i]=p;
            t[p]++;
            ans+=a[i][p];
        }
        int p=0;
        for(int i=1;i<=3;i++){
            if(t[i]>n/2)p=i;
        }
        if(p){
            q=air;
            for(int i=1;i<=n;i++){
                if(club[i]==p){
                    int k=0;
                    for(int j=1;j<=3;j++){
                        if(j==p)continue;
                        if(a[i][p]-a[i][j]<a[i][p]-a[i][k])k=j;
                    }
                    q.push(a[i][p]-a[i][k]);
                }
            }
            while(!q.empty()&&t[p]>n/2){
                ans-=q.top();
                q.pop();
                t[p]--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}