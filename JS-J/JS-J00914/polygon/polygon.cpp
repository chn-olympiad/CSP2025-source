#include<bits/stdc++.h>
using namespace std;
int a[5009],qian[5009],dp[5009][5009],ans,n;
void dfs(int i,int zh,int zd,int sl){
    if(sl>=3){
        if(zh>zd*2) ans++;
    }
    if(i>n){
        return ;
    }
    dfs(i+1,zh+a[i],max(zd,a[i]),sl+1);
    dfs(i+1,zh,zd,sl);
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    int zuhe=0;
    cin>>n;
    int maxx=0,sum=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]>=maxx){
            maxx=a[i];
        }
        sum+=a[i];
    }
    if(n==3){
        if(maxx*2<sum){
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    if(n==4){
        if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))){
            ans++;
        }
        if(a[1]+a[2]+a[4]>max(a[1],max(a[2],a[4]))){
            ans++;
        }
        if(a[4]+a[2]+a[3]>max(a[4],max(a[2],a[3]))){
            ans++;
        }
        if(a[1]+a[2]+a[3]+a[4]>max(a[1],max(a[2],max(a[3],a[4])))){
            ans++;
        }
        cout<<ans;
        return 0;
    }
    if(n==5){
        for(int i=0;i<=1;++i){
            for(int j=0;j<=1;++j){
                for(int k=0;k<=1;++k){
                    for(int l=0;l<=1;++l){
                        for(int m=0;m<=1;++m){
                            if(i+j+k+l+m>=3){
                                if(max(a[i],max(a[j],max(a[k],max(a[l],a[m]))))*2<a[i]+a[j]+a[k]+a[l]+a[m]){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    dfs(0,0,0,0);
    cout<<ans/4;
}
