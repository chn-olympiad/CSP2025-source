#include<bits/stdc++.h>
using namespace std;
int T,n,t[100005],b[100005];
struct node{
    int x,y,z;
}a[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
            int ma=max(a[i].x,max(a[i].y,a[i].z));
            if(a[i].x==ma){
                cnt1++;
                t[i]=1;
            }
            else if(a[i].y==ma){
                cnt2++;
                t[i]=2;
            }
            else if(a[i].z==ma){
                cnt3++;
                t[i]=3;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=max(a[i].x,max(a[i].y,a[i].z));
        }
        if(cnt1*2>n){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(t[i]==1){
                    b[++cnt]=a[i].x-max(a[i].y,a[i].z);
                }
            }
            sort(b+1,b+cnt+1);
            cnt1-=n/2;
            for(int i=1;i<=cnt1;i++){
                ans-=b[i];
            }
        }
        else if(cnt2*2>n){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(t[i]==2){
                    b[++cnt]=a[i].y-max(a[i].x,a[i].z);
                }
            }
            sort(b+1,b+cnt+1);
            cnt2-=n/2;
            for(int i=1;i<=cnt2;i++){
                ans-=b[i];
            }
        }
        else if(cnt3*2>n){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(t[i]==3){
                    b[++cnt]=a[i].z-max(a[i].x,a[i].y);
                }
            }
            sort(b+1,b+cnt+1);
            cnt3-=n/2;
            for(int i=1;i<=cnt3;i++){
                ans-=b[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
5
x y z
a b c

x

n/2
*/
