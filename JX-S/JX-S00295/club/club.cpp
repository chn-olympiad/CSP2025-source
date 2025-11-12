#include<bits/stdc++.h>
using namespace std;
int t,n;
struct my{
    int x,y,z;
}a[100010];
int s[4];
bool cmp(my a,my b){
    return max(a.x,max(a.y,a.z))<max(b.x,max(b.y,b.z));
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d",&n);
        for(int j=1;j<=n;j++){
            scanf("%d%d%d",&a[j].x,&a[j].y,&a[j].z);
        }
        int ans=0;
        s[1]=s[2]=s[3]=0;
        sort(a+1,a+1+n,cmp);
        for(int j=1;j<=n;j++){
            if(a[j].x==max(a[j].x,max(a[j].y,a[j].z))){
                if(s[1]*2<n/2){
                    s[1]++;
                    ans+=a[j].x;
                }else if(a[j].y>a[j].z){
                    s[2]++;
                    ans+=a[j].y;
                }else{
                    s[3]++;
                    ans+=a[j].z;
                }
            }else if(a[j].y==max(a[j].x,max(a[j].y,a[j].z))){
                if(s[2]<n/2){
                    s[2]++;
                    ans+=a[j].y;
                }else if(a[j].x>a[j].z){
                    s[1]++;
                    ans+=a[j].x;
                }else{
                    s[3]++;
                    ans+=a[j].z;
                }
            }else{
                if(s[3]*2<=n){
                    s[3]++;
                    ans+=a[j].z;
                }else if(a[j].y>a[j].x){
                    s[2]++;
                    ans+=a[j].y;
                }else{
                    s[1]++;
                    ans+=a[j].x;
                }
            }

        }
        printf("%d\n",ans);
    }
    return 0;
}
