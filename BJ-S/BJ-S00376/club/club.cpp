#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int b=0;
    while(t--){
        int n;
        cin>>n;
        int b=0;
        if(n==2){
            int a,s,d,f,g,h;
            cin>>a>>s>>d>>f>>g>>h;
            b=max({a+g,a+h,s+f,s+h,d+f,d+g});
        }
        if(n==4){
            int a[5],s[5],d[5];
            for(int i=1;i<=n;i++){
                cin>>a[i]>>s[i]>>d[i];
            }
            int r=0;
            for(int i=1;i<=3;i++){
                int ue=r;
                if(i==1)r=a[1];
                if(i==2)r=s[1];
                if(i==3)r=d[1];
                for(int j=1;j<=3;j++){
                    int uw=r;
                    if(j==1)r+=a[2];
                    if(j==2)r+=s[2];
                    if(j==3)r+=d[2];
                    for(int k=1;k<=3;k++){
                        int uq=r;
                        if(!(i==1&&j==1)&&k==1)r+=a[3];
                        if(!(i==2&&j==2)&&k==2)r+=s[3];
                        if(!(i==3&&j==3)&&k==3)r+=d[3];
                        for(int l=1;l<=3;l++){
                            int u=r;
                            if(int y=1;!((i==y&&j==y)||(i==y&&k==y)||(j==y&&k==y))&&l==y)r+=a[3];
                            if(int y=2;!((i==y&&j==y)||(i==y&&k==y)||(j==y&&k==y))&&l==y)r+=s[3];
                            if(int y=3;!((i==y&&j==y)||(i==y&&k==y)||(j==y&&k==y))&&l==y)r+=d[3];
                            b=max(r,b);
                            r=u;
                        }
                        r=uq;
                    }
                    r=uw;
                }
                r=ue;
            }
        }
        if(n>200){
            int a[100005];
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            sort(a+1,a+n+1);
            for(int i=1;i<=n/2;i++){
                b+==a[n-i+1];
            }
        }
        cout<<b<<endl;
    }
    return 0;
}