#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e4+10;
int t;
int cnt=0,ans[4]={0};
ll n,a[MAXN],b[MAXN],c[MAXN];
int myd(int x,int y,int z){
    cnt+=max(x,y,z);
    return cnt;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--&&n%2==0){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        for(int i=1;i<=n;i++){
            myd(a[i],b[i],c[i]);
            if(cnt+=a[i]){
                ans[1]++;
            }
            if(ans[1]>n/2){
                cnt=max(a[i-1]+a[i],a[i]+a[i+1],a[i+1]+a[i+2]);
            }
            if(cnt+=b[i]){
                ans[2]++;
            }
            if(ans[2]>n/2){
                cnt=max(b[i-1]+b[i],b[i]+b[i+1],b[i+1]+b[i+2]);
            }
            if(cnt+=c[i]){
                ans[3]++;
            }
            if(ans[3]>n/2){
                cnt=max(c[i-1]+c[i],c[i]+c[i+1],c[i+1]+c[i+2]);
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
