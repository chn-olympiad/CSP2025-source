#include <iostream>
#include <queue>
using namespace std;
int n,k;
struct NODE {
    int l;
    int r;
};
int a[500005];
int sum[500005];//before's all's xor
queue<NODE> que;
int ans;
int ll=1,lr=1;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k&&i!=n){//the least
            ans++;
            if(sum[i-1]==k) ans++;
            sum[i]=0;
            que.push(NODE{ll,i-1});
            ll=i+1;
            continue;
        }
        sum[i]=sum[i-1]^a[i];
        if(sum[i]==k){
            sum[i]=0;
            ans++;
            ll=i+1;
        }
        if(sum[i]==0){
            lr=i;
            que.push(NODE{ll,lr});
            ll=i+1;
        }
    }
    if(sum[n]==k) ans++;
    else que.push(NODE{ll,n});
    int er=0;
    while(!que.empty()){
        NODE u=que.front();
        que.pop();
        if(u.r-u.l<2)continue;
        int l=u.l,r=u.r;
        int fg=0;
        for(int i=l;i<r;i++){
            for(int j=l+1;j<=r;j++){
                if(sum[j]^sum[i]==k){
                    ans++;
                    er=j+1;
                    fg=1;
                    break;
                }
            }
            if(fg==1)break;
        }
        while(1){
            fg=0;
            for(int i=er;i<r;i++){
                for(int j=er+1;j<=r;j++){
                    if(sum[j]^sum[i]==k){
                        ans++;
                        er=j+1;
                        fg=1;
                        break;
                    }
                }
                if(fg==1) break;
            }
            break;
        }
    }
    cout<<ans;
    return 0;
}

