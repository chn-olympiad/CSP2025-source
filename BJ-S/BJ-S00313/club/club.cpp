#include <bits/stdc++.h>

using namespace std;
struct pm{
    long long a1;
    long long a2;
    long long a3;
    long long zx;
};
long long t,n,ans,b[100005],c[5],dl;
pm  a[300005],d[300005];
bool cmp(pm n1,pm m1){
    return n1.a1>m1.a1;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        ans=0;
        cin>>n;
        dl=0;
        c[1]=0;
        c[2]=0;
        c[3]=0;
        for(int j=1;j<=n;j++){
            b[j]=0;
            cin>>a[j].a1>>a[j].a2>>a[j].a3;
            if(a[j].a1>=a[j].a2&&a[j].a2>=a[j].a3){
                a[j].zx=a[j].a2;
            }
            if(a[j].a3>=a[j].a2&&a[j].a2>=a[j].a1){
                a[j].zx=a[j].a2;
            }
            if(a[j].a2>=a[j].a1&&a[j].a1>=a[j].a3){
                a[j].zx=a[j].a1;
            }
            if(a[j].a3>=a[j].a1&&a[j].a1>=a[j].a2){
                a[j].zx=a[j].a1;
            }
            if(a[j].a2>=a[j].a3&&a[j].a3>=a[j].a1){
                a[j].zx=a[j].a3;
            }
            if(a[j].a1>=a[j].a3&&a[j].a3>=a[j].a2){
                a[j].zx=a[j].a3;
            }
            d[dl].a1=a[j].a1-a[j].zx;
            d[dl].a2=j;
            d[dl].a3=1;
            d[dl].zx=a[j].zx;
            dl++;
            d[dl].a1=a[j].a2-a[j].zx;
            d[dl].a2=j;
            d[dl].a3=2;
            d[dl].zx=a[j].zx;
            dl++;
            d[dl].a1=a[j].a3-a[j].zx;
            d[dl].a2=j;
            d[dl].a3=3;
            d[dl].zx=a[j].zx;
            dl++;
        }
        sort(d,d+dl,cmp);
        for(int j=0;j<dl;j++){
            if(c[d[j].a3]<n/2&&b[d[j].a2]==0){
                ans=ans+d[j].zx+d[j].a1;
                c[d[j].a3]++;
                b[d[j].a2]++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
