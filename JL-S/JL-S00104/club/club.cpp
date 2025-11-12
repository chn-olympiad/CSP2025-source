#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,a[10001],b[10001],c[10001];
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        int x=0,sum=0;
        int d=n/2;
        int e=n/2;
        int f=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(a[i]>x){
               x=a[i];
               d=d-1;
               sum+=a[i];
               if(b[i]>x){
                    x=b[i];
                    d=d+1;
                    e=e-1;
                    sum=sum-a[i];
                    sum=sum+b[i];
                    if(c[i]>x){
                        x=c[i];
                        e=e+1;
                        f=f-1;
                        sum=sum-b[i];
                        sum=sum+c[i];
                    }
                }
            }
            if(d<0){
                d=d+1;
                sum=sum-a[i];
                if(b[i]>c[i]){
                    e=e-1;
                    sum=sum+b[i];
                }
                else{
                    f=f-1;
                    sum=sum+c[i];
                }
            }
            if(e<0){
                e=e+1;
                sum=sum-b[i];
                if(a[i]>c[i]){
                    d=d-1;
                    sum=sum+a[i];
                }
                else{
                    f=f-1;
                    sum=sum+c[i];
                }
            }
            if(f<0){
                f=f+1;
                sum=sum-c[i];
                if(b[i]>a[i]){
                    e=e-1;
                    sum=sum+b[i];
                }
                else{
                    d=d-1;
                    sum=sum+a[i];
                }
            }
        }
        cout<<sum<<endl;
        return 0;
    }
    return 0;
}
