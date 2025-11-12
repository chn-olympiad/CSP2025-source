#include<bits/stdc++.h>
using namespace std;
struct node{
    int id,is,ip;
}f[300030];
int n,t,b[300030],ans,a[5];
bool cmp(node x,node y){
    return x.is>y.is;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=3*n+10;i++){
            f[i].id=f[i].is=b[i]=f[i].ip=0;
        }
        for(int i=0;i<3*n;){
            int tp=0;
            cin>>f[i+1].is;
            f[i+1].ip=1;
            f[i+1].id=i/3+1;
        if(f[i+1].is==0) tp++;
            cin>>f[i+2].is;
            f[i+1].ip=2;
            f[i+2].id=i/3+1;
        if(f[i+2].is==0) tp++;
            cin>>f[i+3].is;
            f[i+1].ip=3;
            f[i+3].id=i/3+1;
        if(f[i+3].is==0) tp++;
        if(tp>=2){
                if(f[i+1].is!=0){
                    ans+=f[i+1].is;

                b[f[i+1].id]=1;
                a[f[i+1].ip]++;
                }
                else if(f[i+2].is!=0){
                    ans+=f[i+2].is;

                b[f[i+2].id]=1;
                a[f[i+2].ip]++;

                }
                else{

                    ans+=f[i+3].is;

                b[f[i+3].id]=1;
                a[f[i+3].ip]++;
                }
        }
            i+=3;
        }
        sort(f+1,f+3*n+1,cmp);
    for(int i=1;i<=3*n;i++){
        if(b[f[i].id]==0 && a[f[i].ip]<n/2){
            ans+=f[i].is;
            b[f[i].id]=1;
            a[f[i].ip]++;
        }
    }
        cout<<ans<<endl;
    }
    return 0;
}
