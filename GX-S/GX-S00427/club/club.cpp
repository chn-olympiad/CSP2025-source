#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][3];
int b[7],vdv[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int sj=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        if(n==2){
            int p,b2,c,d,e,f;
            p=a[1][1]+a[2][2];
            b2=a[1][1]+a[2][3];
            c=a[1][2]+a[2][1];
            d=a[1][2]+a[2][3];
            e=a[1][3]+a[2][1];
            f=a[1][3]+a[2][2];
            b[1]=p;
            b[2]=b2;
            b[3]=c;
            b[4]=d;
            b[5]=e;
            b[6]=f;
            sort(b+1,b+7);
            cout<<b[6]<<endl;
            continue;
        }


        int flag=0;
        for(int i=1;i<=n;i++){
            if(a[i][2]!=0||a[i][3]!=0){
                flag=1;
            }
        }
        if(flag==0){
            for(int i=1;i<=n;i++){
                 vdv[i]=a[i][1];
            }
            sort(vdv+1,vdv+n+1);
            for(int i=n;i>n/2;i--){
                sj+=vdv[i];
            }
            cout<<sj<<endl;
        }

    }
    return 0;
}
