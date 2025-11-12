#include<bits/stdc++.h>
using namespace std;

int n;
long long a[5005],ans3;
const long long INF=998244353;
void dfs(int i,int sum,int u,int k){
    if(i>u){
        if(sum>k){
            ans3++;
            ans3%=INF;
        }
        return ;
    }
    dfs(i+1,sum+a[i],u,k);
    dfs(i+1,sum,u,k);
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool qyi=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            qyi=1;
        }
    }
    if(qyi==0){
            long  long ans=0;
        for(int i=3;i<=n;i++){
            long long x=n,y=i;
            if(x-y<y){
                y=x-y;
            }
            long long sum=1;
            for(int j=x-y+1;j<=x;j++){
                sum*=j;
                sum%=INF;
            }
            long long sum2=1;
            for(int j=2;j<=y;j++){
                sum2*=j;
                sum2%=INF;
            }
            ans=(ans+sum/sum2)%INF;
        }
        cout<<ans;
    }else if(n<=3){
        long long minn=-1,ans=0;
        for(int i=1;i<=n;i++){
            minn=max(minn,a[i]);
            ans+=a[i];
        }
        if(minn*2<ans){
            cout<<1;
        }else{
            cout<<0;
        }
    }else if(n<=20){
        sort(a+1,a+n+1);
        long long sum=a[1]+a[2];
        for(int i=3;i<=n;i++){
            if(sum>a[i]){
                dfs(1,0,i-1,a[i]);
            }
            sum+=a[i];
        }
        cout<<ans3;
    }
    return 0;
}
