#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],x[100005],y[100005],maxn=0,cz[100005];
void dfs(int step,int t,int b,int c,int ans){
    if(step==n){
        maxn=max(maxn,ans);
        return ;
    }
    if(t<n/2) dfs(step+1,t+1,b,c,ans+a[step+1]);
    if(b<n/2) dfs(step+1,t,b+1,c,ans+x[step+1]);
    if(c<n/2) dfs(step+1,t,b,c+1,ans+y[step+1]);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        maxn=0;
        int ccnt=0;
        bool t1=1,t2=1;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i],&x[i],&y[i]);
            if(x[i]!=0) t1=0;
            if(y[i]!=0) t2=0;
        }
        if(t1&&t2){
            sort(a+1,a+n+1);
            for(int i=n/2+1;i<=n;i++){
                maxn+=a[i];
            }
            cout<<maxn<<endl;
        }else if(t2){
            int m1=0,m2=0,m=0;
            for(int i=1;i<=n;i++){
                if(a[i]>x[i]) m1++;
                else if(a[i]<x[i]) m2++;
                else m++;
            }
            if(m1<=n/2&&m2<=n/2){
                for(int i=1;i<=n;i++){
                    maxn+=max(a[i],x[i]);
                }
            }else if(m1>n/2){
                for(int i=1;i<=n;i++){
                   if(a[i]>x[i]){
                        ccnt++;
                        cz[ccnt]=a[i]-x[i];
                   }
                   maxn+=max(a[i],x[i]);
                }
                sort(cz+1,cz+ccnt+1);
                for(int i=1;i<=m1-n/2;i++){
                    maxn-=cz[i];
                }
            }else{
                for(int i=1;i<=n;i++){
                   if(a[i]<x[i]){
                        ccnt++;
                        cz[ccnt]=x[i]-a[i];
                   }
                   maxn+=max(a[i],x[i]);
                }
                sort(cz+1,cz+ccnt+1);
                for(int i=1;i<=m2-n/2;i++){
                    maxn-=cz[i];
                }
            }
            cout<<maxn<<endl;
        }else{
            dfs(1,1,0,0,a[1]);
            dfs(1,0,1,0,x[1]);
            dfs(1,0,0,1,y[1]);
            cout<<maxn<<endl;
        }
    }
    return 0;
}
/*3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
1
10
6 5 0
6 4 0
6 3 0
6 2 0
6 1 0
6 0 0
1 6 0
1 7 0
1 8 0
5 5 0
*/
