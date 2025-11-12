#include<bits/stdc++.h>
using namespace std;
struct bb{
    long long f;
    long long fs;
}b[100009];
bool bj(bb bj1,bb bj2){
    return bj1.fs<bj2.fs;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t,n,i,j,f,s,ans,a[100009][4],c[4],d,e;
    cin>>t;
    while(t>0){
        t-=1;
        ans=0;
        d=0;
        cin>>n;
        for(i=1;i<=3;i+=1){
            c[i]=0;
        }
        for(i=1;i<=n;i+=1){
            a[i][0]=0;
            f=0;
            s=0;
            for(j=1;j<=3;j+=1){
                cin>>a[i][j];
                if(a[i][f]<=a[i][j]){
                    f=j;
                }
            }
            for(j=1;j<=3;j+=1){
                if(a[i][s]<=a[i][j]&&j!=f){
                    s=j;
                }
            }
            c[f]+=1;
            ans+=a[i][f];
            b[i].f=f;
            b[i].fs=a[i][f]-a[i][s];
        }
        sort(b+1,b+n+1,bj);
        for(i=1;i<=3;i+=1){
             if(d<c[i]){
                d=c[i];
                e=i;
             }
        }
        d-=n/2;
        i=1;
        while(d>0){
            if(b[i].f==e){
                ans-=b[i].fs;
                d-=1;
            }
            i+=1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
