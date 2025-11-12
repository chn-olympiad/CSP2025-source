#include<bits/stdc++.h>
using namespace std;
int T;
int a[100005],b[100005],c[100005],d[100005],e[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int m=n/2;
        int f=0,s=0,t=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(a[i]>b[i]&&a[i]>c[i]){
                    f++;
                d[i]=a[i];
                if(b[i]>c[i]){
                    e[i]=a[i]-b[i];
                }else{
                    e[i]=a[i]-c[i];
                }
            }else if(b[i]>a[i]&&b[i]>c[i]){
                s++;
                d[i]=b[i];
                if(a[i]>c[i]){
                    e[i]=b[i]-a[i];
                }else{
                    e[i]=b[i]-c[i];
                }
            }else{
                t++;
                d[i]=c[i];
                if(b[i]>a[i]){
                    e[i]=c[i]-b[i];
                }else{
                    e[i]=c[i]-a[i];
                }
            }
        }
        sort(e+1,e+1+n);
        if(f>m){
            int y=f-m;
            for(int i=1;i<=y;i++){
               d[i]-=e[i];
            }
        }else if(s>m){
            int y=s-m;
            for(int i=1;i<=y;i++){
               d[i]-=e[i];
            }
        }else{
            int y=t-m;
            for(int i=1;i<=y;i++){
               d[i]-=e[i];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=d[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
