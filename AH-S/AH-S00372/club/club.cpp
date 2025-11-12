#include<bits/stdc++.h>
using namespace std;
int T,n,ans,cnt[5];
struct stu{
    int x,y,z;
}a[100005];
bool cmp(const stu &x,const stu &y){
    return x.x>y.x;
}
void dfs(int i,int sum){
    if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2) return ;
    if(i==0){
        ans=max(ans,sum);
        return ;
    }
    sum+=a[i].x;
    cnt[1]++;
    dfs(i-1,sum);
    sum-=a[i].x;
    cnt[1]--;
    sum+=a[i].y;
    cnt[2]++;
    dfs(i-1,sum);
    sum-=a[i].y;
    cnt[2]--;
    sum+=a[i].z;
    cnt[3]++;
    dfs(i-1,sum);
    sum-=a[i].z;
    cnt[3]--;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cnt[1]=cnt[2]=cnt[3]=0;
        int sum=0;
        cin>>n;
        bool ok=false,f=false;
        for(int i=1;i<=n;i++){
                cin>>a[i].x>>a[i].y>>a[i].z;
                if(a[i].y!=0||a[i].z!=0) ok=true;
                if(a[i].z!=0) f=true;
        }
        if(n<=30){
            ans=0;
            dfs(n,0);
            cout<<ans<<endl;
            continue;
        }
        if(ok==false){
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                sum+=a[i].x;
            }
            cout<<sum<<endl;
            continue;
        }

    }
    return 0;
}
