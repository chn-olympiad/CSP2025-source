#include<bits/stdc++.h>
using namespace std;
int t,n,o,tw,th,ans;
bool two,thr;
struct num{
    int o,t,th,m,mt;
};
bool cmp(num a,num b){
    return a.o>b.o;
}
bool cm(num a,num b){
    return a.o<b.o;
}
bool p(num a,num b){
    return a.t<b.t;
}
num a[1000000];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].o>>a[i].t>>a[i].th;
            if(a[i].t!=0){
                two=1;
            }
            if(a[i].th!=0){
                thr=1;
            }
        }
        if(two==0&&thr==0){
            sort(a+1,a+1+n,cmp);
            for(int j=1;j<=n/2;j++){
                ans+=a[j].o;
            }
        }
        else if(thr==0){
            int mo=0,mt=0;
            num b[1000000],c[1000000];
            for(int j=1;j<=n;j++){
                if(a[j].o>=a[j].t&&mo<=n/2){
                    ans+=a[j].o;
                    b[mo]=a[j];

                    sort(b,b+mo,cm);
                    mo++;
                }
                else if(a[j].o<a[j].t&&mt<n/2){
                    ans+=a[j].t;
                    c[mt]=a[j];
                    sort(c,c+mt,p);
                    mt++;
                }
                else if(a[j].o>=a[j].t){
                    if(a[j].o-b[0].o>=a[j].t-b[0].t){
                        ans+=a[j].o;
                        ans-=b[0].o;
                        ans+=b[0].t;
                        mt++;
                        b[0]=a[j];
                        sort(c,c+mt,p);
                        sort(b,b+mo,cm);
                    }
                    else{
                        ans+=a[j].t;
                        mt++;
                        c[mt]=a[j];
                        sort(c,c+mt,p);
                    }
                }
                else{
                    if(a[j].o-b[0].o<=a[j].t-b[0].t){
                        ans+=a[j].t;
                        ans-=b[0].t;
                        ans+=b[0].o;
                        mo++;
                        c[0]=a[j];
                        sort(c,c+mt,p);
                        sort(b,b+mo,cm);
                    }
                    else{
                        ans+=a[j].o;
                        mo++;
                        b[mo]=a[j];
                        sort(b,b+mo,cm);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
