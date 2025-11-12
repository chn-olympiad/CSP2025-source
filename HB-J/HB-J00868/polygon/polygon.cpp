#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,way=0,ans=0,maxa=0;
long long a[5005],book[5005];
int dfs(int x,int now){
        if(x==n+1)return way;
        for(int i=now;i<=n;i++){
            if(!book[i]){
                now=i+1;
                ans+=a[i];
                int lmax=maxa,lnow=now;
                maxa=max(a[i],maxa);
                book[i]=1;
                dfs(x+1,now);
                if(x>=3&&ans-maxa*2>0){
                    way++;
                    way%=998244353;
                }
                now=lnow;
                maxa=lmax;
                ans-=a[i];
                book[i]=0;
            }
        }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,1);
    cout<<way;
    return 0;
}
