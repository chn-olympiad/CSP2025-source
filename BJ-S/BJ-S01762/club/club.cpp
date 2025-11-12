#include<bits/stdc++.h>
using namespace std;
int t,n,f[110][110][110],ans,nl,nr;
struct point{
    int a,b,c;
},a[100010],b[100010],c[100010];
bool cmp1(point x,point y){
    return x.a>y.a;
}
bool cmp2(point x,point y){
    return x.b>y.b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        memset(f,0,sizeof(f));
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;
        if(n<=200){
            for(int i=1;i<=n;i++){
                for(int j=0;j<=min(i,n/2);j++){
                    for(int k=max(0,i-j-n/2);k<=min(n/2,i-j);k++){
                        int l=i-j-k;
                        if(j>0)f[j][k][l]=f[j-1][k][l]+a[i].a;
                        if(k>0)f[j][k][l]=max(f[j][k][l],f[j][k-1][l]+a[i].b);
                        if(l>0)f[j][k][l]=max(f[j][k][l],f[j][k][l-1]+a[i].c);
                        if(i==n)ans=max(ans,f[j][k][l]);
                    }
                }
            }
        }else{
            memcpy(b,a,sizeof(b));
            memcpy(c,a,sizeof(c));
            sort(b+1,b+1+n,cmp1);
            sort(c+1,c+1+n,cmp2);
            for(int i=1;i<=n/2;i++)ans+=b[i].a;
        }
        cout<<ans<<endl;
    }
    return 0;
}
