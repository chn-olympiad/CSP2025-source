#include<bits/stdc++.h>
#define MAXN 100005
#define MAXA 20004
#define ll long long
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    int mds[MAXN][3];
    scanf("%d",&t);
    while(t--){
        memset(mds,0,sizeof(mds));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&mds[i][0]);
            scanf("%d",&mds[i][1]);
            scanf("%d",&mds[i][2]);
        }
        int fn=n>>1;
        int xz1[MAXN]={0};
        int xz2[MAXN]={0};
        int xz3[MAXN]={0};
        for(int i=0;i<n;i++){
            if((mds[i][0]>=mds[i][1])&&(mds[i][0]>=mds[i][2])){
                xz1[0]++;
                xz1[xz1[0]]=i;
            }else if((mds[i][1]>=mds[i][0])&&(mds[i][1]>=mds[i][2])){
                xz2[0]++;
                xz2[xz2[0]]=i;
                // cout << i << " ";
            }else{
                xz3[0]++;
                xz3[xz3[0]]=i;
            }
        }
        if(xz1[0]>fn){
            int nd=xz1[0]-fn;
            int q[nd];
            memset(q,-1,sizeof(q));
            for(int i=1;i<=xz1[0];i++){
                for(int j=0;j<nd;j++){
                    if(q[j]==-1){
                        q[j]=i;
                        break;
                    }
                    int dj1=mds[xz1[q[j]]][0]-max(mds[xz1[q[j]]][1],mds[xz1[q[j]]][2]);
                    int dj2=mds[xz1[i]][0]-max(mds[xz1[i]][1],mds[xz1[i]][2]);
                    if(dj1>dj2){
                        for(int k=nd-1;k>j;k--){
                            int l=q[k-1];
                            q[k]=l;
                        }
                        q[j]=i;
                        break;
                    }
                    
                }
                // for(int i2=0;i2<nd;i2++){
                //     if(q[i2]==-1){
                //         cout << "-1" << " ";
                //     }else{
                //         int dj1=mds[xz1[q[i2]]][0]-max(mds[xz1[q[i2]]][1],mds[xz1[q[i2]]][2]);
                //         cout << dj1 << " ";
                //     }
                // }
                // cout << ":";
            }
            for(int i=0;i<nd;i++){
                int xs=xz1[q[i]];
                // int dj1=max(mds[xz1[q[i]]][1],mds[xz1[q[i]]][2])-mds[xz1[q[i]]][0];
                // cout << dj1 << " ";
                if(mds[xs][1]>mds[xs][2]){
                    xz2[0]++;
                    xz2[xz2[0]]=xs;
                }else{
                    xz3[0]++;
                    xz3[xz3[0]]=xs;
                }
                xz1[q[i]]=-1;
            }
        }else if(xz2[0]>fn){
            int nd=xz2[0]-fn;
            int q[nd];
            memset(q,-1,sizeof(q));
            for(int i=1;i<=xz2[0];i++){
                for(int j=0;j<nd;j++){
                    if(q[j]==-1){
                        q[j]=i;
                        break;
                    }
                    int dj1=max(mds[xz2[q[j]]][0],mds[xz2[q[j]]][2])-mds[xz2[q[j]]][1];
                    int dj2=max(mds[xz2[i]][0],mds[xz2[i]][2])-mds[xz2[i]][1];
                    if(dj1<dj2){
                        for(int k=nd-1;k>j;k--){
                            q[k]=q[k-1];
                        }
                        q[j]=i;
                        break;
                    }
                }
            }
            for(int i=0;i<nd;i++){
                int xs=xz2[q[i]];
                // cout << xs << " ";
                if(mds[xs][0]>mds[xs][2]){
                    xz1[0]++;
                    xz1[xz1[0]]=xs;
                }else{
                    xz3[0]++;
                    xz3[xz3[0]]=xs;
                }
                xz2[q[i]]=-1;
            }
        }else if(xz3[0]>fn){
            int nd=xz3[0]-fn;
            int q[nd];
            memset(q,-1,sizeof(q));
            for(int i=1;i<=xz3[0];i++){
                for(int j=0;j<nd;j++){
                    if(q[j]==-1){
                        q[j]=i;
                        break;
                    }
                    int dj1=max(mds[xz3[q[j]]][1],mds[xz3[q[j]]][0])-mds[xz3[q[j]]][2];
                    int dj2=max(mds[xz3[i]][1],mds[xz3[i]][0])-mds[xz3[i]][2];
                    if(dj1<dj2){
                        for(int k=nd-1;k>j;k--){
                            q[k]=q[k-1];
                        }
                        q[j]=i;
                        break;
                    }
                }
            }
            for(int i=0;i<nd;i++){
                int xs=xz3[q[i]];
                if(mds[xs][0]>mds[xs][1]){
                    xz1[0]++;
                    xz1[xz1[0]]=xs;
                }else{
                    xz2[0]++;
                    xz2[xz2[0]]=xs;
                }
                xz3[q[i]]=-1;
            }
        }
        ll result=0;
        for(int i=1;i<=xz1[0];i++){
            if(xz1[i]==-1) continue;
            result+=mds[xz1[i]][0];
        }
        for(int i=1;i<=xz2[0];i++){
            if(xz2[i]==-1) continue;
            result+=mds[xz2[i]][1];
        }
        for(int i=1;i<=xz3[0];i++){
            if(xz3[i]==-1) continue;
            result+=mds[xz3[i]][2];
        }
        printf("%lld\n",result);
    }
    return 0;
}