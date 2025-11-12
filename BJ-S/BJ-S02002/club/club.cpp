#include <bits/stdc++.h>
using namespace std;
int t,n,x,y,z,maxn,maxh,ans;
struct human{
    int g1,g2,g3,f,s,gf;
}a[100005];
bool cmp(human a,human b){
    if(a.f!=maxn){
        return 0;
    }else if(b.f!=maxn){
        return 1;
    }else{
        if(a.gf>b.gf){
            return 1;
        }
        return 0;
    }
    return 0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        x=0;
        y=0;
        z=0;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].g1>>a[i].g2>>a[i].g3;
            if(a[i].g1>=a[i].g2&&a[i].g1>=a[i].g3){
                a[i].f=1;
                if(a[i].g2>=a[i].g3){
                    a[i].s=2;
                    a[i].gf=a[i].g1-a[i].g2;
                }else{
                    a[i].s=3;
                    a[i].gf=a[i].g1-a[i].g3;
                }
            }else if(a[i].g2>=a[i].g1&&a[i].g2>=a[i].g3){
                a[i].f=2;
                if(a[i].g1>=a[i].g3){
                    a[i].s=1;
                    a[i].gf=a[i].g2-a[i].g1;
                }else{
                    a[i].s=3;
                    a[i].gf=a[i].g2-a[i].g3;
                }
            }else{
                a[i].f=3;
                if(a[i].g1>=a[i].g2){
                    a[i].s=1;
                    a[i].gf=a[i].g3-a[i].g1;
                }else{
                    a[i].s=2;
                    a[i].gf=a[i].g3-a[i].g2;
                }
            }
            if(a[i].f==1){
                x++;
            }else if(a[i].f==2){
                y++;
            }else{
                z++;
            }
        }
        if(max(x,max(y,z))>n/2){
            if(x>=y&&x>=z){
                maxn=1;
                maxh=x;
            }else if(y>=x&&y>=z){
                maxn=2;
                maxh=y;
            }else{
                maxn=3;
                maxh=z;
            }
            sort(a+1,a+n+1,cmp);
            for(int i=n/2+1;i<=maxh;i++){
                a[i].f=a[i].s;
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i].f==1){
                ans+=a[i].g1;
            }else if(a[i].f==2){
                ans+=a[i].g2;
            }else{
                ans+=a[i].g3;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
