#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005][5];
int p1[100005],p2[100005],p3[100005],k1,k2,k3,ans;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        k1=k2=k3=0;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]) p1[++k1]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
            if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]) p2[++k2]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
            if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]) p3[++k3]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
            ans+=max(a[i][1],max(a[i][2],a[i][3]));
        }
        if(k1>n/2){
            for(int i=1;i<=k1-n/2;i++){
                int minn=INT_MAX,minx;
                for(int j=1;j<=k1;j++){
                    if(p1[j]<minn) minn=p1[j],minx=j;
                }
                ans-=minn;
                p1[minx]=INT_MAX;
            }
        }
        if(k2>n/2){
            for(int i=1;i<=k2-n/2;i++){
                int minn=INT_MAX,minx;
                for(int j=1;j<=k2;j++){
                    if(p2[j]<minn) minn=p2[j],minx=j;
                }
                ans-=minn;
                p2[minx]=INT_MAX;
            }
        }
        if(k3>n/2){
            for(int i=1;i<=k3-n/2;i++){
                int minn=INT_MAX,minx;
                for(int j=1;j<=k3;j++){
                    if(p3[j]<minn) minn=p3[j],minx=j;
                }
                ans-=minn;
                p3[minx]=INT_MAX;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
