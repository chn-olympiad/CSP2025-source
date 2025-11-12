#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
struct node{
    int x,y,z,del;
}a[N];
int T,n,sum1,sum2,sum3,ans,jsq;
bool cmp(node a,node b){
    return a.del<b.del;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        jsq=sum1=sum2=sum3=ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            int mx=max(a[i].x,max(a[i].y,a[i].z));
            if(a[i].x==mx)sum1++;
            else if(a[i].y==mx)sum2++;
            else sum3++;
            ans+=mx;
        }
        int mx=max(sum1,max(sum2,sum3));
        if(mx<=n/2){
            cout<<ans<<'\n';
            continue;
        }
        if(sum2==mx){
            for(int i=1;i<=n;i++){
                swap(a[i].x,a[i].y);
            }
        }
        else if(sum3==mx){
            for(int i=1;i<=n;i++){
                swap(a[i].x,a[i].z);
            }
        }
        sum1=0;
        for(int i=1;i<=n;i++){
            int mx=max(a[i].x,max(a[i].y,a[i].z));
            if(a[i].x==mx)sum1++;
            a[i].del=a[i].x-max(a[i].y,a[i].z);
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++){
            if(a[i].del<0)continue;
            jsq++;
            ans-=a[i].del;
            if(sum1-jsq==n/2)break;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
