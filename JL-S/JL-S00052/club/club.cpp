#include<bits/stdc++.h>
using namespace std;
int _,n,ans,c[3];
struct g{
    int x,y,z;
}a[100010];
struct h{
    int e,f;
}b[5][100010],w;
bool d(h i,h j){
    return i.f>j.f;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>_;
    while(_--){
        ans=0;
        cin>>n;
        c[1]=c[2]=c[3]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
                w.e=i;
                w.f=a[i].x;
                b[1][c[1]++]=w;
            }
            else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
                w.e=i;
                w.f=a[i].y;
                b[2][c[2]++]=w;
            }
            else{
                w.e=i;
                w.f=a[i].z;
                b[3][c[3]++]=w;
            }
        }
        sort(b[1]+1,b[1]+c[1]+1,d);
        sort(b[2]+1,b[2]+c[2]+1,d);
        sort(b[3]+1,b[3]+c[3]+1,d);
        if(c[1]<n/2&&c[2]<n/2&&c[3]<n/2){
            for(int i=1;i<=c[1];i++){
                ans+=b[1][i].f;
            }
            for(int i=1;i<=c[2];i++){
                ans+=b[2][i].f;
            }
            for(int i=1;i<=c[1];i++){
                ans+=b[3][i].f;
            }
            cout<<ans;
            continue;
        }
        if(c[1]==n){
            for(int i=1;i<=n/2;i++){
                if(a[b[1][i].e].y>=a[b[1][i].e].z){
                    w.e=i;
                    w.f=a[i].y;
                    b[2][c[2]++]=w;
                }
                else{
                    w.e=i;
                    w.f=a[i].z;
                    b[3][c[3]++]=w;
                }
            }
            for(int i=1;i<=c[1];i++){
                ans+=b[1][i].f;
            }
            for(int i=1;i<=c[2];i++){
                ans+=b[2][i].f;
            }
            for(int i=1;i<=c[1];i++){
                ans+=b[3][i].f;
            }
            cout<<ans;
            continue;
        }
        if(c[2]>n/2){
            for(int i=1;i<=c[2]-n/2;i++){
                if(a[b[2][i].e].x>=a[b[2][i].e].z){
                    w.e=i;
                    w.f=a[i].x;
                    b[1][c[1]++]=w;
                }
                else{
                    w.e=i;
                    w.f=a[i].z;
                    b[3][c[3]++]=w;
                }
            }
        }
        else if(c[1]>n/2){
            for(int i=1;i<=c[1]-n/2;i++){
                if(a[b[1][i].e].y>=a[b[1][i].e].z){
                    w.e=i;
                    w.f=a[i].y;
                    b[2][c[2]++]=w;
                }
                else{
                    w.e=i;
                    w.f=a[i].z;
                    b[3][c[3]++]=w;
                }
            }
        }
        else{
            for(int i=1;i<=c[3]-n/2;i++){
                if(a[b[3][i].e].x>=a[b[3][i].e].y){
                    w.e=i;
                    w.f=a[i].x;
                    b[1][c[1]++]=w;
                }
                else{
                    w.e=i;
                    w.f=a[i].y;
                    b[2][c[2]++]=w;
                }
            }
        }
        for(int i=1;i<=c[1];i++){
            ans+=b[1][i].f;
        }
        for(int i=1;i<=c[2];i++){
            ans+=b[2][i].f;
        }
        for(int i=1;i<=c[1];i++){
            ans+=b[3][i].f;
        }
        cout<<ans;
        continue;
    }
    return 0;
}
