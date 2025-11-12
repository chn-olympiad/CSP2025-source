#include <bits/stdc++.h>
using namespace std;
int t,n,x,y,z,a[100001],b[100001],c[100001];
long long ans;
bool cmp(int s,int e){
    return s<e;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0,a[0]=0,b[0]=0,c[0]=0;
        for(int i=1;i<=n;i++){
            cin>>x>>y>>z;
            if(x>=y&&y>=z){
                a[++a[0]]=x-y;
                ans+=x;
            }
            else if(x>=z&&y<=z){
                a[++a[0]]=x-z;
                ans+=x;
            }
            else if(y>=x&&x>=z){
                b[++b[0]]=y-x;
                ans+=y;
            }
            else if(y>=z&&z>=x){
                b[++b[0]]=y-z;
                ans+=y;
            }
            else if(z>=x&&x>=y){
                c[++c[0]]=z-x;
                ans+=z;
            }
            else{
                c[++c[0]]=z-y;
                ans+=z;
            }
            //cout<<b[0];
        }
        if(a[0]>n/2){
            sort(a+1,a+a[0]+1,cmp);
            for(int i=1;i<=a[0]-n/2;i++){
                ans-=a[i];
            }
        }
        else if(b[0]>n/2){
            sort(b+1,b+b[0]+1,cmp);
            for(int i=1;i<=b[0]-n/2;i++){
                ans-=b[i];
                //cout<<b[i]<<" ";
            }
        }
        else if(c[0]>n/2){
            sort(c+1,c+c[0]+1,cmp);
            for(int i=1;i<=c[0]-n/2;i++){
                ans-=c[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
