#include<bits/stdc++.h>
using namespace std;
int n;
int t;
int a[100005][3];
int x[100005];
int y[100005];
int sum[3];
int ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d",&n);
        sum[0]=sum[1]=sum[2]=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
            int tmp=max(max(a[i][0],a[i][1]),a[i][2]);
            if(tmp==a[i][0]){
                sum[0]++;
                x[i]=0;
            }else if(tmp==a[i][1]){
                sum[1]++;
                x[i]=1;
            }else {
                sum[2]++;
                x[i]=2;
            }ans+=tmp;
        }y[0]=0;
        if(sum[0]>n/2){
            int tmp=sum[0]-n/2;
            for(int i=1;i<=n;i++){
                if(x[i]==0){
                    y[++y[0]]=a[i][0]-max(a[i][1],a[i][2]);
                }
            }
            sort(y+1,y+1+sum[0]);
            for(int i=1;i<=tmp;i++){
                ans-=y[i];
            }
        }
        else if(sum[1]>n/2){
            int tmp=sum[1]-n/2;
            for(int i=1;i<=n;i++){
                if(x[i]==1){
                    y[++y[0]]=a[i][1]-max(a[i][0],a[i][2]);
                }
            }
            sort(y+1,y+1+sum[1]);
            for(int i=1;i<=tmp;i++){
                ans-=y[i];
            }
        }
        else if(sum[2]>n/2){
            int tmp=sum[2]-n/2;
            for(int i=1;i<=n;i++){
                if(x[i]==2){
                    y[++y[0]]=a[i][2]-max(a[i][1],a[i][0]);
                }
            }
            sort(y+1,y+1+sum[2]);
            for(int i=1;i<=tmp;i++){
                ans-=y[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
//Ren5Jie4Di4Ling5% 