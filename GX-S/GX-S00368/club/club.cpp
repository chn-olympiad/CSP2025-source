#include<bits/stdc++.h>
using namespace std;

struct ars{
    int a1,a2,a3;
    bool ky=true;
}a[100010];

bool cmp(ars c1,ars c2){
    if(c1.a2<=c2.a2&&c1.a3<=c2.a3) return c1.a1>c2.a1;
    else if(c1.a1<=c2.a1&&c1.a3<=c2.a3) return c1.a2>c2.a2;
    else if(c1.a1<=c2.a1&&c1.a2<=c2.a2) return c1.a3>c2.a3;
}

int t,n,ans;
int b1,b2,b3;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int l=1;l<=t;l++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++){
            if(a[i].a1>a[i].a2&&a[i].a1>a[i].a3&&b1<n/2){
                ans+=a[i].a1;
                b1++;
                a[i].ky=false;
            }
            else if(a[i].a2>a[i].a1&&a[i].a2>a[i].a3&&b2<n/2){
                ans+=a[i].a2;
                b2++;
                a[i].ky=false;
            }
            else if(a[i].a3>a[i].a2&&a[i].a3>a[i].a1&&b3<n/2){
                ans+=a[i].a3;
                b3++;
                a[i].ky=false;
            }
        }
        if(b1<n/2||b2<n/2||b3<n/2){
            for(int i=1;i<=n;i++){
                if(a[i].ky){
                    if(a[i].a1>a[i].a2&&a[i].a1>a[i].a3&&b1<n/2){
                        ans+=a[i].a1;
                        b1++;
                    }
                    else if(a[i].a2>a[i].a1&&a[i].a2>a[i].a3&&b2<n/2){
                        ans+=a[i].a2;
                        b2++;
                    }
                    else if(a[i].a3>a[i].a2&&a[i].a3>a[i].a1&&b3<n/2){
                        ans+=a[i].a3;
                        b3++;
                    }
                }
            }
        }
        b1=0;
        b2=0;
        b3=0;
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
