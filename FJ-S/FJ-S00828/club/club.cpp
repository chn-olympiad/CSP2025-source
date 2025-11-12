#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void rd(int &p){
    p=0;char z=getchar();int f(0);
    while(z>'9'||z<'0'){if(z=='-')f^=1;z=getchar();}
    while(z>='0'&&z<='9')p=(p<<1)+(p<<3)+z-'0',z=getchar();
    if(f)p=-p;
}
void rdl(ll &p){
    p=0;char z=getchar();int f(0);
    while(z>'9'||z<'0'){if(z=='-')f^=1;z=getchar();}
    while(z>='0'&&z<='9')p=(p<<1)+(p<<3)+z-'0',z=getchar();
    if(f)p=-p;
}
const int N=1e5+5;
int t,n,a[N][3],c[3],b[N],num,d[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    rd(t);
    while(t--){
        rd(n);ll ans(0);
        for(int i(1);i<=n;++i){
            rd(a[i][0]);rd(a[i][1]);rd(a[i][2]);
        }memset(c,0,sizeof(c));
        for(int i(1);i<=n;++i){
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
                ++c[0];ans+=a[i][0];d[i]=0;
            }
            else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
                ++c[1];ans+=a[i][1];d[i]=1;
            }
            else{
                ++c[2];ans+=a[i][2];d[i]=2;
            }
        }
        if(max(c[0],max(c[1],c[2]))<=n/2)printf("%lld\n",ans);
        else{num=0;
            if(c[0]>n/2){
                for(int i(1);i<=n;++i){
                    if(d[i]==0){
                        b[++num]=max(a[i][1],a[i][2])-a[i][0];
                    }
                }sort(b+1,b+num+1);
                for(int i(1);i<=c[0]-n/2;++i)ans+=b[num-i+1];
            }
            if(c[1]>n/2){
                for(int i(1);i<=n;++i){
                    if(d[i]==1){
                        b[++num]=max(a[i][0],a[i][2])-a[i][1];
                    }
                }sort(b+1,b+num+1);
                for(int i(1);i<=c[1]-n/2;++i)ans+=b[num-i+1];
            }
            if(c[2]>n/2){
                for(int i(1);i<=n;++i){
                    if(d[i]==2){
                        b[++num]=max(a[i][1],a[i][0])-a[i][2];
                    }
                }sort(b+1,b+num+1);
                for(int i(1);i<=c[2]-n/2;++i)ans+=b[num-i+1];
            }printf("%lld\n",ans);
        }
    }
    return 0;
}