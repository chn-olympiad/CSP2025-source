#include<bits/stdc++.h>
using namespace std;
struct c{
    int x;
    int y;
    int z;
    int m;
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,b=0;
    int k[205]={},kk=0;
    c a[205]={};
    int o=0,p=0,q=0;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a[j].x>>a[j].y>>a[j].z;
            if(a[j].x>a[j].y&&a[j].x>a[j].z){
                o++;
                b+=a[j].x;
                a[j].m=min(a[j].x-a[j].y,a[j].x-a[j].z);
                k[kk]=j;
                kk++;
            }
            else if(a[j].y>a[j].z&&a[j].y>a[j].x){
                p++;
                b+=a[j].y;
                a[j].m=min(a[j].y-a[j].x,a[j].y-a[j].z);
            }
            else if(a[j].z>a[j].y&&a[j].z>a[j].x){
                q++;
                b+=a[j].z;
                a[j].m=min(a[j].z-a[j].y,a[j].z-a[j].x);
            }
        }
        if(o<=n/2&&p<=n/2&&q<=n/2){
            cout<<b;
            o=0;
            p=0;
            q=0;
            b=0;
        }
    }
    return 0;
}
