#include<bits/stdc++.h>
using namespace std;
int _,n,f[100100];
struct node{
    int x,y,z;
};
node a[100100];
bool cmp(node x,node y){
    return abs(x.x-x.y)>abs(y.x-y.y);
}
bool cmp1(node x,node y){
    return abs(x.y-x.z)>abs(y.y-y.z);
}
bool cmp2(node x,node y){
    return abs(x.z-x.x)>abs(y.z-y.x);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>_;
    while(_--){
        cin>>n;
        int ans=0,x=n/2,y=n/2,z=n/2,ans1=0,ans2=0,x1=n/2,x2=n/2,y1=n/2,y2=n/2,z1=n/2,z2=n/2;
        for(int i=1; i<=n; i++){
            a[i].x=0;
            a[i].y=0;
            a[i].z=0;
            f[i]=0;
        }
        for(int i=1; i<=n; i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1; i<=n; i++){
            if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
                if(x!=0){
                    x--;
                    ans+=a[i].x;
                    f[i]=1;
                }else if(a[i].y>=a[i].z){
                    ans+=a[i].y;
                    y--;
                }else{
                    z--;
                    ans+=a[i].z;
                }
            }else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
                if(y!=0){
                    y--;
                    ans+=a[i].y;
                    f[i]=1;
                }else if(a[i].x>=a[i].z){
                    ans+=a[i].x;
                    x--;
                }else{
                    ans+=a[i].z;
                    z--;
                }
            }else if(a[i].z>=a[i].x&&a[i].z>=a[i].y){
                if(z!=0){
                    z--;
                    ans+=a[i].z;
                }else if(a[i].x>=a[i].y){
                    ans+=a[i].x;
                    x--;
                }else{
                    ans+=a[i].y;
                    y--;
                }
            }
        }
        sort(a+1,a+1+n,cmp1);
        for(int i=1; i<=n; i++){
            if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
                if(x1!=0){
                    x1--;
                    ans1+=a[i].x;
                }else if(a[i].y>=a[i].z){
                    ans1+=a[i].y;
                    y1--;
                }else{
                    z1--;
                    ans1+=a[i].z;
                }
            }else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
                if(y1!=0){
                    y1--;
                    ans1+=a[i].y;
                }else if(a[i].x>=a[i].z){
                    ans1+=a[i].x;
                    x1--;
                }else{
                    ans1+=a[i].z;
                    z1--;
                }
            }else if(a[i].z>=a[i].x&&a[i].z>=a[i].y){
                if(z1!=0){
                    z1--;
                    ans1+=a[i].z;
                }else if(a[i].x>=a[i].y){
                    ans1+=a[i].x;
                    x1--;
                }else{
                    ans1+=a[i].y;
                    y1--;
                }
            }
        }
        sort(a+1,a+1+n,cmp2);
        for(int i=1; i<=n; i++){
            if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
                if(x2!=0){
                    x2--;
                    ans2+=a[i].x;
                }else if(a[i].y>=a[i].z){
                    ans2+=a[i].y;
                    y2--;
                }else{
                    z2--;
                    ans2+=a[i].z;
                }
            }else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
                if(y2!=0){
                    y2--;
                    ans2+=a[i].y;
                }else if(a[i].x>=a[i].z){
                    ans2+=a[i].x;
                    x2--;
                }else{
                    ans2+=a[i].z;
                    z2--;
                }
            }else if(a[i].z>=a[i].x&&a[i].z>=a[i].y){
                if(z2!=0){
                    z2--;
                    ans2+=a[i].z;
                }else if(a[i].x>=a[i].y){
                    ans2+=a[i].x;
                    x2--;
                }else{
                    ans2+=a[i].y;
                    y2--;
                }
            }
        }
        cout<<max(ans1,max(ans2,ans))<<endl;
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
