#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;
int T,n,ans,t[4];
struct node{
    int x,y,z,tx,ty,tz;
}a[N];
inline bool cmp(node X,node Y){
    int cx1=X.x-X.y,cx2=X.y-X.z,cy1=Y.x-Y.y,cy2=Y.y-Y.z;
    if(cx1==cy1)return cx2>cy2;
    return cx1>cy1;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].x>=a[i].y){
                if(a[i].y>=a[i].z){
                    a[i].tx=0,a[i].ty=1,a[i].tz=2;
                }
                else if(a[i].z>=a[i].x){
                    a[i].tx=2,a[i].ty=0,a[i].tz=1;
                    swap(a[i].z,a[i].x);
                    swap(a[i].z,a[i].y);
                }
                else{
                    a[i].tx=0,a[i].ty=2,a[i].tz=1;
                    swap(a[i].y,a[i].z);
                }
            }
            if(a[i].y>=a[i].x){
                if(a[i].y<=a[i].z){
                    a[i].tx=2,a[i].ty=1,a[i].tz=0;
                    swap(a[i].x,a[i].z);
                }
                else if(a[i].x>=a[i].z){
                    a[i].tx=1,a[i].ty=0,a[i].tz=2;
                    swap(a[i].y,a[i].x);
                }
                else{
                    a[i].tx=1,a[i].ty=2,a[i].tz=0;
                    swap(a[i].y,a[i].x);
                    swap(a[i].y,a[i].z);
                }
            }
        }
        sort(a+1,a+n+1,cmp);
        // for(int i=1;i<=n;i++){
        //     cout<<a[i].x<<','<<a[i].tx<<' '<<a[i].y<<','<<a[i].ty<<' '<<a[i].z<<','<<a[i].tz<<'\n';
        // }
        t[0]=t[1]=t[2]=0;
        ans=0;
        for(int i=1;i<=n;i++){
            if(t[a[i].tx]>=n/2)ans+=a[i].y,t[a[i].ty]++;
            else ans+=a[i].x,t[a[i].tx]++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/