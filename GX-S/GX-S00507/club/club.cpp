#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,ans;
struct node{
    int a1,a2,a3,v;
}a[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            a[i].v=0;
        }
        for(int i=1;i<=n;i++){
            if(a[i].a1>a[i].a2&&a[i].a1>a[i].a3&&a[i].v==0){
                ans+=a[i].a1;a[i].v=1;
            }
            else if(a[i].a2>a[i].a1&&a[i].a2>a[i].a3&&a[i].v==0){
                ans+=a[i].a2;a[i].v=1;
            }
            else if(a[i].v==0){
                ans+=a[i].a3;
                a[i].v=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
