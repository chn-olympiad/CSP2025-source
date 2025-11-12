#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5+5;
int t,n,cnt[5];
struct node{
    int pos;
    int data;
};
node a[mxN][5];
bool cmp(node x,node y){
    return x.data>y.data;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",a[i][j].data);
                a[i][j].pos=j;
            }
            stable_sort(a[i]+1,a[i]+1+3,cmp);
        }
        for(int i=1;i<=n;i++){
            int idx=a[i][1].pos;
            if(cnt[idx]<=n/2) cnt[idx]++;
            else{
                int mi=INT_MAX;
                int p;
                for(int r=1;r<i;r++){
                    if(mi>a[r][1].data-a[r][2].data){
                        mi=a[r][1].data-a[r][2].data;
                        p=r;
                    }
                }
                if(mi<a[i][1].data-a[i][2].data) swap(a[p][1],a[p][2]),swap(a[p][2],a[p][3]);
                else swap(a[i][1],a[i][2]),swap(a[i][2],a[i][3]);
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++) sum+=a[i][1].data;
        printf("%d",sum);
    }
    return 0;
}
