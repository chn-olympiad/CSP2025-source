#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005],c[1000005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int x;
    cin>>x;
    for(int i=1;i<=x;i++){
        int y,aa=0,bb=0,cc=0,sum=0;
        int yu[1000005];
        cin>>y;
        for(int j=1;j<=y;j++){
            cin>>a[j]>>b[j]>>c[j];
            if(a[j]>=b[j]&&a[j]>=c[j]){
                aa++;
                sum+=a[j];
            }else if(b[j]>=a[j]&&b[j]>=c[j]){
                bb++;
                sum+=b[j];
            }else{
                cc++;
                sum+=c[j];
            }
        }
        int m=1;
        if(aa>y/2){
            for(int k=1;k<=y;k++){
                if(a[k]>=b[k]&&a[k]>=c[k]){
                    yu[m]=a[k]-max(b[k],c[k]);
                    m++;
                }
            }
            sort(yu+1,yu+aa+1);
            for(int k=1;k<=aa-y/2;k++){
                sum-=yu[k];
            }
        }else if(bb>y/2){
            for(int k=1;k<=y;k++){
                if(b[k]>=a[k]&&b[k]>=c[k]){
                    yu[m]=b[k]-max(a[k],c[k]);
                    m++;
                }
            }
            sort(yu+1,yu+bb+1);
            for(int k=1;k<=bb-y/2;k++){
                sum-=yu[k];
            }
        }else{
            for(int k=1;k<=y;k++){
                if(c[k]>=a[k]&&b[k]<=c[k]){
                    yu[m]=c[k]-max(a[k],b[k]);
                    m++;
                }
            }
            sort(yu+1,yu+cc+1);
            for(int k=1;k<=cc-y/2;k++){
                sum-=yu[k];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
