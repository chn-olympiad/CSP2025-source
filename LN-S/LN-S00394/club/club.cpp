#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
struct p{
    int id,f,d;
}a[3*N];
bool v[N];
bool cmp(p x,p y){
    return x.f>y.f;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        memset(a,0,sizeof(a));
        memset(v,0,sizeof(v));
        for(int i=1;i<=n;i++){
            a[i].d=i;a[i+n].d=i;a[i+n+n].d=i;
            a[i].id=1;a[i+n].id=2;a[i+n+n].id=3;
            cin>>a[i].f>>a[i+n].f>>a[i+n+n].f;
        }
        sort(a+1,a+3*n+1,cmp);
        int x=0,y=0,z=0,xh=0,yh=0,zh=0;
        for(int i=1;i<=n*3;i++){
            if(v[a[i].d]==0){
                int q=a[i].id;
                v[a[i].d]=1;
                if(q==1&&(x+1)<=n/2){
                    x++;
                    xh+=a[i].f;
                }
                if(q==2&&(y+1)<=n/2){
                    y++;
                    yh+=a[i].f;
                }
                if(q==3&&(z+1)<=n/2){
                    z++;
                    zh+=a[i].f;
                }
            }
        }
        cout<<zh+xh+yh<<"\n";
    }
    return 0;
}