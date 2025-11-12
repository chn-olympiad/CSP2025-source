#include<bits/stdc++.h>
using namespace std;
int n;
int mx=-1;
struct cc{
    int x,y,z;
}a[100005];
bool cmp(cc x,cc y){
    return x.x>y.x||x.x==y.x&&x.y>y.y||x.x==y.x&&x.y==y.y&&x.z>y.z;
}
void dfs(int in,int sum,int aa,int bb,int cc){
    if(aa>n/2||bb>n/2||cc>n/2){
        return;
    }
    if(in==n){
        mx=max(mx,sum);
        return;
    }
   // cout<<sum<<" ";
    dfs(in+1,sum+a[in+1].x,aa+1,bb,cc);
    dfs(in+1,sum+a[in+1].y,aa,bb+1,cc);
    dfs(in+1,sum+a[in+1].z,aa,bb,cc+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    for(int k=1;k<=T;k++){
        scanf("%d",&n);
        int io=1,jo=1;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
            if(a[i].y>0){
                io=0;
            }
            if(a[i].z>0){
                jo=0;
            }
        }
        sort(a+1,a+n+1,cmp);
        if(io==1&&jo==1){
            int sum=0;
            for(int i=1;i<=n/2;i++){
                sum+=a[i].x;
            }
            printf("%d\n",sum);
        }else if(jo==1){
            int sum1=0,sum2=0;
            for(int i=1;i<=n;i++){
                if(i<=n/2){
                    sum1+=a[i].x;
                    sum2+=a[i].y;
                }else{
                    sum1+=a[i].y;
                    sum2+=a[i].x;
                }
            }
            printf("%d\n",max(sum1,sum2));
        }else if(n==2){
            int mx=max(a[1].x+a[2].y,mx);
            mx=max(mx,a[1].x+a[2].z);
            mx=max(a[1].y+a[2].x,mx);
            mx=max(mx,a[1].y+a[2].z);
            mx=max(mx,a[1].z+a[2].y);
            mx=max(a[1].z+a[2].x,mx);
            printf("%d\n",mx);
        }
    }
return 0;
}
//Ren5Jie4Di4Ling5%
//5 3 4   3 5 1   5 3 4
//4 2 1   5 3 4   3 2 4
//3 5 1   3 2 4   4 2 1
//3 2 4   4 2 1   3 5 1
