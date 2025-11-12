#include<bits/stdc++.h>
using namespace std;
int n,m,t,sx,sy,sz;
long long ans1,ans2,ans3,ans;
struct stu{
    int x,y,z;
}a[100005];
bool cmp(stu a,stu b){
    if(a.x!=b.x) return a.x>b.x;
    return a.y<b.y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=sx=sy=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(a[i].x>=a[i].y&&sx<n/2){
                ans+=a[i].x;
                sx++;
            }else{
                if(sy<n/2){
                    ans+=a[i].y;
                    sy++;
                }

            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
