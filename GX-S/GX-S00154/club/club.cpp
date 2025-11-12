#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct node{
    int v;
    int i;
};
int x,y,z;
int ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans=x=y=z=0;
        int n;
        cin>>n;
        int maxx=n/2;
        node a[N][10];
        for(int i=1;i<=n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            a[i][1]={x,1};
            a[i][2]={y,2};
            a[i][3]={z,3};
            if(a[i][1].v<a[i][2].v) swap(a[i][1],a[i][2]);
            if(a[i][1].v<a[i][3].v) swap(a[i][1],a[i][3]);
            if(a[i][2].v<a[i][3].v) swap(a[i][2],a[i][3]);
        }
        for(int i=1;i<=n;i++){
            if(a[i][1].i==1&&x<maxx){
                x++;
                ans+=a[i][1].v;
                continue;
            }
            if(a[i][1].i==2&&y<maxx){
                y++;
                ans+=a[i][1].v;
                continue;
            }
            if(a[i][1].i==3&&z<maxx){
                z++;
                ans+=a[i][1].v;
                continue;
            }



            if(a[i][2].i==1&&x<maxx){
                x++;
                ans+=a[i][2].v;
                continue;
            }
            if(a[i][2].i==2&&y<maxx){
                y++;
                ans+=a[i][2].v;
                continue;
            }
            if(a[i][2].i==3&&z<maxx){
                z++;
                ans+=a[i][2].v;
                continue;
            }



            if(a[i][3].i==1&&x<maxx){
                x++;
                ans+=a[i][3].v;
                continue;
            }
            if(a[i][3].i==2&&y<maxx){
                y++;
                ans+=a[i][3].v;
                continue;
            }
            if(a[i][3].i==3&&z<maxx){
                z++;
                ans+=a[i][3].v;
                continue;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
