#include<bits/stdc++.h>
using namespace std;
int a[100000],b[100000],c[100000],d[1000000],f[1000000],e[1000000],a1[10000000];
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdin);
int n,m,x=0,cnt=0;
cin>>n;
for(int i=1;i<=n;i++){
        cin>>m;
        x=m/2;
for(int j=1;j<=m;j++)cin>>a[j]>>b[j]>>c[j];
}
int sum1=0,sum2=0,sum3=0;
for(int i=1;i<=n;i++){
  sum1=0,sum2=0,sum3=0;
for(int j=1;j<=m;j++){
    if(a[j]>=b[j]){
        if(a[j]>=c[j]){
                d[j]=a[j];
                sum1++;
                f[j]=c[j];
                e[j]=b[j];
        }
        else{
                d[j]=c[j];
                sum3++;
                f[j]=a[j];
                e[j]=b[j];
        }

    }
    else{
            if(b[j]>=c[j]){
                    d[j]=b[j];
                    sum2++;
                    f[j]=c[j];
                e[j]=a[j];
            }
    else{
            d[j]=c[j];
            f[j]=b[j];
                e[j]=a[j];
    sum3++;
    }
}
cnt+=a[j];

}
cout<<cnt<<endl;

}
return 0;
}


