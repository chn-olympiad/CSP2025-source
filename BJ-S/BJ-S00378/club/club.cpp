#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t,n,a[N][4],st[N],num[4],len;
void print(int pos){
    int ans=0,sum=0;
    for(int i = 1;i <= n;i++){
        ans+=max(a[i][1],max(a[i][2],a[i][3]));
    }
    if(pos==0){
        printf("%d\n",ans);
        return;
    }
    for(int i = 1;i <= n;i++){
        int x=a[i][1],y=a[i][2],z=a[i][3];
        if(x>=y&&x>=z){
            if(pos==1) st[++len]=x-max(y,z);
        }else if(y>=x&&y>=z){
            if(pos==2) st[++len]=y-max(x,z);
        }else{
            if(pos==3) st[++len]=z-max(x,y);
        }
    }
    sort(st+1,st+len+1);
    for(int i = 1;i <= num[pos]-n/2;i++){
        sum+=st[i];
    }
    printf("%d\n",ans-sum);
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int pos=0;
        for(int i = 1;i <= 3;i++) num[i]=0;
        len=0;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            int x=a[i][1],y=a[i][2],z=a[i][3];
            if(x>=y&&x>=z) num[1]++;
            else if(y>=x&&y>=z) num[2]++;
            else num[3]++;
        }
        if(num[1]>n/2) pos=1;
        else if(num[2]>n/2) pos=2;
        else if(num[3]>n/2) pos=3;
        print(pos);
    }
    return 0;
}
