#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int app(int e,int w){
    if(e==1) return a[w];
    else if(e==2) return b[w];
    else return c[w];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,t;
    cin>>t;
    bool f1,f2;
    int maxx=0;
    int ddv[4];
    while(t--){
        f1=1,f2=1;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        for(int i=1;i<=n;i++){
            if(b[i]!=0) f1=0;
            if(c[i]!=0){
                f2=0;
                f1=0;
            }
        }
        if(f1==1){
            long long sum=0;
            sort(a+1,a+n+1);
            for(int i=n/2+1;i<=n;i++){
                sum+=a[i];
            }
            cout<<sum;
        }
        else if(n==2){
            maxx=-1;
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    if(i!=j and maxx<app(i,1)+app(j,2)){
                        maxx=app(i,1)+app(j,2);
                    }
                }
            }
            cout<<maxx;
        }else{
        }


        cout<<endl;
    }
    return 0;
}
