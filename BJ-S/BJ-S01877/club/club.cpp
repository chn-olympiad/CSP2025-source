#include<bits/stdc++.h>
using namespace std;
long long T,n;
struct S{
    long long s1,s2,s3;
}a[100005];
long long ans,an1;
long long o1,o2,o3;
void dfs(long long x){
    if(x==n+1){
        ans=max(ans,an1);
    }
    if(o1<n/2&&o2<n/2&&o3<n/2){
        o1++;an1+=a[x].s1;
        dfs(x+1);
        o1--;an1-=a[x].s1;
        o2++;an1+=a[x].s2;
        dfs(x+1);
        o2--;an1-=a[x].s2;
        o3++;an1+=a[x].s3;
        dfs(x+1);
        o3--;an1-=a[x].s3;
    }else{
        if(o1>=n/2&&o2<n/2&&o3<n/2){
            o2++;an1+=a[x].s2;
            dfs(x+1);
            o2--;an1-=a[x].s2;
            o3++;an1+=a[x].s3;
            dfs(x+1);
            o3--;an1-=a[x].s3;
        }else if(o2>=n/2&&o1<n/2&&o3<n/2){
            o1++;an1+=a[x].s1;
            dfs(x+1);
            o1--;an1-=a[x].s1;
            o3++;an1+=a[x].s3;
            dfs(x+1);
            o3--;an1-=a[x].s3;
        }else if(o3>=n/2&&o1<n/2&&o2<n/2){
            o1++;an1+=a[x].s1;
            dfs(x+1);
            o1--;an1-=a[x].s1;
            o2++;an1+=a[x].s2;
            dfs(x+1);
            o2--;an1-=a[x].s2;
        }else if(o1<n/2&&o2>=n/2&&o3>=n/2){
            o1++;an1+=a[x].s1;
            dfs(x+1);
            o1--;an1-=a[x].s1;
        }else if(o1>=n/2&&o2<n/2&&o3>=n/2){
            o2++;an1+=a[x].s2;
            dfs(x+1);
            o2--;an1-=a[x].s2;
        }else if(o1>=n/2&&o2>=n/2&&o3<n/2){
            o3++;an1+=a[x].s3;
            dfs(x+1);
            o3--;an1-=a[x].s3;
        }
    }

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        an1=0,ans=0,o1=0,o2=0,o3=0;
        memset(a,0,sizeof(a));
        cin>>n;
        for(long long i=1;i<=n;i++){
            cin>>a[i].s1>>a[i].s2>>a[i].s3;
        }
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
