#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t;
struct pst{
    ll id;
    ll x,y,z,like;
}a[100010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    if(t==1){
        ll n,cnt;
        cin>>n;
        ll c1,c2,c3;
        ll top=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].like=max(a[i].x,max(a[i].y,a[i].z));
            for(int j=1;j<=3;j++){
                if(a[i].like==a[j].x||a[i].like==a[j].y||a[i].like==a[i].z){
                    a[i].id=j;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i].id==1){
                c1++;
            }
            if(a[i].id==2){
                c2++;
            }
            if(a[i].id==3){
                c3++;
            }
        }
        if(c1<=top&&c2<=top&&c3<=top){
            for(int i=1;i<=n;i++){
                cnt+=a[i].like;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

