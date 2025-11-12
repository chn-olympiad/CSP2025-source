#include<bits/stdc++.h>
using namespace std;
long long T,n,f[205][105][105],ans,flag;
struct node{
    long long a[5];
}a[100005];
bool cmp(node x,node y){
    return x.a[1]<y.a[1];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        memset(f,0,sizeof(f));
        cin>>n;
        flag=1;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i].a[1],&a[i].a[2],&a[i].a[3]);
            if(a[i].a[3]||a[i].a[2])flag=0;
        }
        if(flag){
            sort(a+1,a+n+1,cmp);
            for(int i=n;i>n/2;i--){
                ans+=a[i].a[1];
            }
            cout<<ans<<endl;
            continue;
        }
        if(n<=200){
            for(int i=1;i<=n;i++){
                for(int j=0;j<=min(i*1ll,n/2);j++){
                    for(int k=0;k<=min(i-j*1ll,n/2);k++){
                        int l=i-j-k;
                        if(l>n/2)continue;
                        if(j)f[i][j][k]=f[i-1][j-1][k]+a[i].a[1];
                        if(k)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i].a[2]);
                        if(l)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].a[3]);
                        ans=max(ans,f[i][j][k]);
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

