#include<bits/stdc++.h>
using namespace std;
int a[100100][4],b[100100];
struct A{
    int d,f;
}c[100100];
long long ans;
int prin[100100];
bool ta=1,tb=1;
bool cmp(int a,int b){
    return a>b;
}
bool cmp2(A a,A b){
    return a.d>b.d;
}
void dfs(int i,int n,long long u,int d1,int d2,int d3){
    if(d1>(n/2)||d2>(n/2)||d3>(n/2)){
        return ;
    }
    if(i==n+1){
        ans=max(ans,u);
        
        return ;
    }
    prin[i]=1;
    dfs(i+1,n,u+a[i][1],d1+1,d2,d3);
    prin[i]=2;
    dfs(i+1,n,u+a[i][2],d1,d2+1,d3);
    prin[i]=3;
    dfs(i+1,n,u+a[i][3],d1,d2,d3+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        ans=0;
        ta=1;
        tb=1;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&a[i][j]);
                if((j==2||j==3)&&a[i][j]!=0){
                    ta=0;
                }
                if((j==3)&&a[i][j]!=0){
                    tb=0;
                }
            }
        }if(ta==1){
            for(int i=1;i<=n;i++){
                b[i]=a[i][1];
            }
            sort(b+1,b+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=b[i];
            }
        }else if(tb==1){
            for(int i=1;i<=n;i++){
                c[i].d=a[i][2]-a[i][1];
                c[i].f=i;
            }
            sort(c+1,c+n+1,cmp2);
            for(int i=1;i<=n/2;i++){
                ans+=a[c[i].f][2];
            }
            for(int i=n/2+1;i<=n;i++){
                ans+=a[c[i].f][1];
            }
        }else if(n<=30){
            dfs(1,n,0,0,0,0);
        }else{

        }
        printf("%lld\n",ans);
    }
    return 0;
}