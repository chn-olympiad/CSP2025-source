#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100006][4],ans;
long long vis[4];
bool c1,c2,c3;
long long sum1,sum2,m1,m2;
long long p1[100006],p2[100006];
bool cmp(long long x,long long y){
    return x>y;
}
void dfs(long long pos,long long sum){
    if(pos>=n){
        ans=max(ans,sum);
        return ;
    }
    if(vis[1]+1<=n/2){
        vis[1]++;
        dfs(pos+1,sum+a[pos+1][1]);
        vis[1]--;
    }
    if(vis[2]+1<=n/2){
        vis[2]++;
        dfs(pos+1,sum+a[pos+1][2]);
        vis[2]--;
    }
    if(vis[3]+1<=n/2){
        vis[3]++;
        dfs(pos+1,sum+a[pos+1][3]);
        vis[3]--;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld %lld %lld",&a[i][1],&a[i][2],&a[i][3]);
            if(a[i][2]==0&&a[i][3]==0)sum1++;
            if(a[i][3]==0)sum2++;
            if(sum1==n)c1=1;
            if(sum2==n)c2=1;
            m1=max(m1,max(a[i][1],max(a[i][2],a[i][3])));
            m2=min(m2,min(a[i][1],min(a[i][2],a[i][3])));
            if(m1==2&&m2==0)c3=1;

        }
        if(c1){
            for(int i=1;i<=n;i++){
                p1[i]=a[i][1];
            }
            sort(p1+1,p1+1+n,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=p1[i];
            }
            printf("%lld\n",ans);
            continue;
        }
        if(c2){

        }
        if(c3){
            for(int i=1;i<=n;i++){
                long long x=a[i][1];
                long long y=a[i][2];
                long long z=a[i][3];
                long long big=max(x,max(y,z));
                if(x==big){
                    if(vis[1]+1<=n/2){
                        vis[1]++;
                        ans+=x;
                    }
                    else{
                        long long nb=max(y,z);
                        if(y==nb){
                            if(vis[2]+1<=n/2){
                                vis[2]++;
                                ans+=y;
                            }
                            else{
                                vis[3]++;
                                ans+=z;
                            }
                        }else{
                             if(vis[3]+1<=n/2){
                                 vis[3]++;
                                 ans+=z;
                             }
                             else{
                                vis[2]++;
                                ans+=y;
                             }

                    }
                }
                }
                else if(y==big){
                    if(vis[2]+1<=n/2){
                        vis[2]++;
                        ans+=y;
                    }
                    else{
                        long long nb=max(x,z);
                        if(x==nb){
                            if(vis[1]+1<=n/2){
                                vis[1]++;
                                ans+=x;
                            }
                            else{
                                vis[3]++;
                                ans+=z;
                            }
                        }else{
                             if(vis[3]+1<=n/2){
                                 vis[3]++;
                                 ans+=z;
                             }
                             else{
                                vis[1]++;
                                ans+=x;
               }

             }
            }


          }
          else{
            if(vis[3]+1<=n/2){
                        vis[3]++;
                        ans+=z;
                    }
                    else{
                        long long nb=max(x,y);
                        if(x==nb){
                            if(vis[1]+1<=n/2){
                                vis[1]++;
                                ans+=x;
                            }
                            else{
                                vis[2]++;
                                ans+=y;
                            }
                        }else{
                             if(vis[2]+1<=n/2){
                                 vis[2]++;
                                 ans+=y;
                             }
                             else{
                                vis[1]++;
                                ans+=x;
               }

             }
            }

          }
         }
         printf("%lld\n",ans);
         continue;
        }
        else{
            dfs(0,0);
            printf("%lld\n",ans);
        }
        ans=0;
        vis[1]=vis[2]=vis[3]=0;
    }
    return 0;
}
