#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll T,n,a[N],b[N],c[N],ans,l[5],xc,yc,zc,t1,t2,t3;
struct node{
    ll id,d;
}x[N],y[N],z[N];
bool cmp(node x,node y){
    return x.d>y.d;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        ans=xc=yc=zc=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>l[1]>>l[2]>>l[3];
            t1=l[1];t2=l[2];t3=l[3];
            sort(l+1,l+3+1);
            a[i]=l[3];
            b[i]=l[2];
            c[i]=l[1];
            if(a[i]==t1){
                xc++;
                x[xc].id=i;
                x[xc].d=a[i]-b[i];
            }else if(a[i]==t2){
                yc++;
                y[yc].id=i;
                y[yc].d=a[i]-b[i];
            }else{
                zc++;
                z[zc].id=i;
                z[zc].d=a[i]-b[i];
            }
        }
 //       cout<<xc<<" ";
        if(xc>(n/2)){
            sort(x+1,x+xc+1,cmp);
            for(int i=1;i<=xc;i++){
                if(i>n/2) ans+=b[x[i].id];
                else ans+=a[x[i].id];
//                cout<<ans<<" ";
            }
        }else{
            for(int i=1;i<=xc;i++) ans+=a[x[i].id];
        }

        if(yc>(n/2)){
            sort(y+1,y+yc+1,cmp);
            for(int i=1;i<=yc;i++){
                if(i>n/2) ans+=b[y[i].id];
                else ans+=a[y[i].id];
//                cout<<ans<<" ";
            }
        }else{
            for(int i=1;i<=yc;i++) ans+=a[y[i].id];
        }

        if(zc>(n/2)){
            sort(z+1,z+zc+1,cmp);
            for(int i=1;i<=zc;i++){
                if(i>n/2) ans+=b[z[i].id];
                else ans+=a[z[i].id];
//                cout<<ans<<" ";
            }
        }else{
            for(int i=1;i<=zc;i++) ans+=a[z[i].id];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*

*/
