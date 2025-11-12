#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int pian[t];
    for(int p=0;p<t;p++){
        int n=0,num=0;
        int x=0,y=0,z=0;
        int k=0;
        cin>>n;
        int a[n],b[n],c[n];
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]==0)
                x++;
            if(c[i]==0)
                y++;
            if(a[i]==0)
                z++;
        }
        if(n==2){
            if(a[0]+b[1]>num)
                num=a[0]+b[1];
            if(a[0]+c[1]>num)
                num=a[0]+c[1];
            if(b[0]+a[1]>num)
                num=b[0]+a[1];
            if(b[0]+c[1]>num)
                num=b[0]+c[1];
            if(c[0]+a[1]>num)
                num=c[0]+a[1];
            if(c[0]+b[1]>num)
                num=c[0]+b[1];
            pian[p]=num;
            continue;
        }
        if(x==n&&y==n){
            sort(a,a+n);
            for(int i=n-1;i>=n/2;i--)
                num+=a[i];
            pian[p]=num;
            continue;
        }
        if(y==n&&z==n){
            sort(b,b+n);
            for(int i=n-1;i>=n/2;i--)
                num+=b[i];
            pian[p]=num;
            continue;
        }
        if(x==n&&z==n){
            sort(c,c+n);
            for(int i=n-1;i>=n/2;i--)
                num+=c[i];
            pian[p]=num;
            continue;
        }
        if(n==4){
            if(a[0]>b[0]&&a[0]>=c[0]){
                num+=a[0];
            }
            if(b[0]>a[0]&&b[0]>=c[0]){
                num+=b[0];
            }
            if(c[0]>b[0]&&c[0]>=a[0]){
                num+=c[0];
            }
            if(a[1]>b[1]&&a[1]>=c[1]){
                num+=a[1];
            }
            if(b[1]>a[1]&&b[1]>=c[1]){
                num+=b[1];
            }
            if(c[1]>b[1]&&c[1]>=a[1]){
                num+=c[1];
            }
            if(a[2]>b[2]&&a[2]>=c[2]){
                num+=a[2];
            }
            if(b[2]>a[2]&&b[2]>=c[2]){
                num+=b[2];
            }
            if(c[2]>b[2]&&c[2]>=a[2]){
                num+=c[2];
            }
            if(a[3]>b[3]&&a[3]>=c[3]){
                num+=a[3];
            }
            if(b[3]>a[3]&&b[3]>=c[3]){
                num+=b[3];
            }
            if(c[3]>b[3]&&c[3]>=a[3]){
                num+=c[3];
            }
            pian[p]=num;
            continue;
        }
    }
    for(int i=0;i<t;i++)
        cout<<pian[i]<<endl;
    return 0;
}
