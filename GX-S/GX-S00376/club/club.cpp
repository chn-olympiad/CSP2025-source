#include<bits/stdc++.h>
using namespace std;
int a[10001][10001],b[10001][10001],x;
int c[10001][10001],n,m,t,da=0,db=0,dc=0,e[100],f=3;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1,j=1;i<=t;i++){
        cin>>n;
        for(x=1;x<=n;x++){
            cin>>a[i][x]>>b[i][x]>>c[i][x];
            m=max(a[i][x],b[i][x]);
            m=max(m,c[i][x]);
            if(m==a[i][x]) da++;
            if(m==b[i][x]) db++;
            if(m==c[i][x]) dc++;
            e[i]+=m;
            if(a[i][x]>=10){
                if(b[i][x]<10) e[i]=e[i]-a[i][x]+b[i][x];
                else if(c[i][x]<10) e[i]=e[i]-a[i][x]+c[i][x];
            }
            if(b[i][x]>=10){
                if(a[i][x]<10) e[i]=e[i]-b[i][x]+b[i][x];
                else if(c[i][x]<10) e[i]=e[i]-b[i][x]+c[i][x];
            }
            if(c[i][x]>=10){
                if(a[i][x]<10) e[i]=e[i]-c[i][x]+a[i][x];
                else if(b[i][x]<10) e[i]=e[i]-c[i][x]+b[i][x];
            }
        }
        if(da>n/2){
            da-=n/2;
            if(db<n/2){
                db+=(n-n/2);
            for(int q=n/2+1;q<=n;q++){
                e[i]=e[i]-a[i][q]+b[i][q];
                }
            }
            else if(dc<n/2){
                dc+=(n-n/2);
            for(int q=n/2+1;q<=n;q++){
                e[i]=e[i]-a[i][q]+c[i][q];
                }
            }
        }
        if(db>n/2){
            db-=n/2;
            if(da<n/2){
                da+=(n-n/2);
            for(int q=n/2+1;q<=n;q++){
                e[i]=e[i]-b[i][q]+a[i][q];
                }
            }
            else if(dc<n/2){
                dc+=(n-n/2);
            for(int q=n/2+1;q<=n;q++){
                e[i]=e[i]-b[i][q]+c[i][q];
                }
            }
        }
        if(dc>n/2){
            dc-=n/2;
            if(da<n/2){
                da+=(n-n/2);
            for(int q=n/2+1;q<=n;q++){
                e[i]=e[i]-c[i][q]+a[i][q];
                }
            }
            else if(db<n/2){
                db+=(n-n/2);
            for(int q=n/2+1;q<=n;q++){
                e[i]=e[i]-c[i][q]+b[i][q];
                }
            }
        }
    }
    for(int j=1;j<=t;j++){
        cout<<e[j]<<endl;
    }
    return 0;
}
