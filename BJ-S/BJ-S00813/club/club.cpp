#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
    int x,y,z;
}a[N];
int n,t,num=0,xnum=0,ynum=0,znum=0;


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
        }

        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i].x<=a[j].x){
                    swap(a[i].x,a[j].x);
                    swap(a[i].y,a[j].y);
                    swap(a[i].z,a[j].z);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i].x>a[i].y&&a[i].x>a[i].z&&xnum<n/2){
                xnum++;
                num+=a[i].x;
            }
            else if(a[i].y>a[i].x&&a[i].y>a[i].z&&ynum<n/2){
                ynum++;
                num+=a[i].y;
            }
            else if(znum<n/2){
                znum++;
                num+=a[i].z;
            }
        }
        cout<<num<<endl;
    }





















    return 0;
}