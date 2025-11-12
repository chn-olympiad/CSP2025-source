#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,maxb[N],a,b,c,ans,v1[4],vvv,vv;
struct sss{
    int x,y,z,maxa;
}e[N];
bool cmp(sss g,sss f){
    return g.maxa<f.maxa;
}
void dfs(int i,int sum){
    if(i==n+1){
        ans=max(ans,sum);
//        cout<<"a"<<sum<<endl;
//        cout<<v1[1]<<v1[2]<<v1[3]<<endl;
        return ;
    }
    for(int j=1;j<=3;j++){
        if(v1[j]==(n/2)){
            continue;
        }
        if(j==1){
            v1[j]++;
            dfs(i+1,sum+e[i].x);
            v1[j]--;
        }else if(j==2){
            v1[j]++;
            dfs(i+1,sum+e[i].y);
            v1[j]--;
        }else{
            v1[j]++;
            dfs(i+1,sum+e[i].z);
            v1[j]--;
        }
    }
}
bool f=false;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        scanf("%d",&n);
        f=false;
        int x,y,z,maxva=0,maxvb=0,maxvc=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
            e[i].maxa=max(e[i].x,max(e[i].y,e[i].z));
            if(e[i].maxa==e[i].x){
                maxva++;
            }
            else if(e[i].maxa==e[i].y){
                maxvb++;
            }else{
                maxvc++;
            }
            if(e[i].y==0&&e[i].z==0){
                vvv++;
            }else if(e[i].z==0){
                vv++;
            }
        }
        if(vvv==n){
            sort(e+1,e+1+n,cmp);
            for(int i=n;i>(n/2);i--){
                ans+=e[i].x;
            }
            printf("%d\n",ans);
            vvv=0;
            f=true;
        }else if(vv==n&&f==false){
           // cout<<maxva<<' '<<maxvb<<endl;
            if(maxva==maxvb){
                for(int i=n;i>=1;i--){
                    ans+=e[i].maxa;
                }
                printf("%d\n",ans);
            }else if(maxva+maxvb>n){
                for(int i=n;i>=1;i--){
                    ans+=e[i].maxa;
                }
                printf("%d\n",ans);
            }else{
                sort(e+1,e+1+n,cmp);
                int aaa=0,bbb=0,i;
                for(i=n;i>=1;i--){
                   // cout<<e[i].x<<' '<<e[i].y<<endl;
                }
                for(i=n;i>=1;i--){
                    if(aaa==(n/2)){
                        aaa=-1;
                        break;
                    }else if(bbb==(n/2)){
                        bbb=-1;
                        break;
                    }
                    ans+=e[i].maxa;
                    if(e[i].maxa==e[i].x){
                        aaa++;
                    }else{
                        bbb++;
                    }
                }
                for(;i>=1;i--){
                    if(aaa==-1){
                        ans+=e[i].y;
                    }else{
                        ans+=e[i].x;
                    }
                }
                printf("%d\n",ans);
            }
            f=true;
            vv=0;
        }
        if(n<=30&&f==false){
            dfs(1,0);
            printf("%d\n",ans);
        }
        ans=0;
        v1[1]=v1[2]=v1[3]=0;
    }
    return 0;
}
