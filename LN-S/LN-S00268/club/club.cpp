#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100010][5];

int f[5][100010];
int l[5];
int ans;
int ma(int x){
    if(a[x][1]>=a[x][2]&&a[x][1]>=a[x][3])return 1;
    else if(a[x][2]>=a[x][3])return 2;
    return 3;
}bool cmp(int x,int y){
    return a[x][3]-a[x][2]>a[y][3]-a[y][2];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans=0;
        l[1]=l[2]=l[3]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&a[i][j]);
            }f[ma(i)][++l[ma(i)]]=i;
            sort(a[i]+1,a[i]+3+1);
            ans+=a[i][3];
        }for(int i=1;i<=3;i++){
            if(l[i]>n/2){
                sort(f[i]+1,f[i]+l[i]+1,cmp);
                for(int j=n/2+1;j<=l[i];j++){
                    ans+=a[f[i][j]][2]-a[f[i][j]][3];
                }
            }
        }printf("%d\n",ans);
    }
    return 0;
}
