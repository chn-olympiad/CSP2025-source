#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct node{
    int num[4],pos[4];
}d[maxn];
int a[maxn][4],cnt[4];
int t,n,len;
bool cmp1(node x,node y){
    if(x.num[1]-x.num[2]==y.num[1]-y.num[2]&&x.num[2]-x.num[3]==y.num[2]-y.num[3])return x.num[1]>y.num[1];
    if(x.num[1]-x.num[2]==y.num[1]-y.num[2])return x.num[2]-x.num[3]>y.num[2]-y.num[3];
    return x.num[1]-x.num[2]>y.num[1]-y.num[2];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        // len=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cnt[j]=0;
                scanf("%d",&a[i][j]);
                d[i].num[j]=a[i][j];
                d[i].pos[j]=j;
            }
            for(int j=1;j<=3;j++){
                for(int k=j+1;k<=3;k++){
                    if(d[i].num[j]<d[i].num[k]){
                        swap(d[i].num[j],d[i].num[k]);
                        swap(d[i].pos[j],d[i].pos[k]);
                    }
                }
            }

        }
        sort(d+1,d+n+1,cmp1);
        // cout<<"stop\n";
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=3;j++){
        //         cout<<d[i].pos[j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"----\n";
        // for(int i=1;i<=n;i++){
        //         for(int j=1;j<=3;j++){
        //             cout<<d[i].num[j]<<" ";
        //         }
        //         cout<<endl;
        //     }
        // cout<<"----\n";
        for(int i=1;i<=n;i++){
            if(cnt[d[i].pos[1]]+1<=n/2){
                cnt[d[i].pos[1]]++;
                ans+=d[i].num[1];
            }
            else{
                if(cnt[d[i].pos[2]]+1<=n/2){
                    cnt[d[i].pos[2]]++;
                    ans+=d[i].num[2];
                }
                else{
                    if(cnt[d[i].pos[3]]+1<=n/2){
                        cnt[d[i].pos[3]]++;
                        ans+=d[i].num[3];
                    }
                }
            }
        }
        printf("%d\n",ans);
    }


    return 0;
}