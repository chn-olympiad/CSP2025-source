#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long b[5005];
long long cnt;
bool cmp(int x,int y){
    return x>y;
}
void dfs(int x,int y){
    if(b[x]<=y){
        return;
    }
    if(x==n){
        return;
    }
    int i=x+1;
    for(;i<=n&&a[i]+a[i+1]>y;i++){
        int l=i+1,r=n,mid;
        bool aaa=0;
        while(l<=r){
            mid=l+r>>1;
            if(a[mid]+a[i]<=y)r=mid-1;
            else{
                    l=mid+1;
                    aaa=1;
            }
        }
        if(aaa){
            for(int j=i+1;j<=r;j++){
                int ll=n-j;
                long long sum=1;
                for(int i=1;i<=ll;i++){
                    sum*=2;
                    sum%=998244353;
                }
                cnt+=sum;
                cnt%=998244353;
            }
            dfs(r,y-a[i]);
        }
    }
    for(;i<=n;i++){
        dfs(i,y-a[i]);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=n;i>=1;i--){
        b[i]=b[i+1]+a[i];
    }
    for(int i=1;i<=n;i++){
        dfs(i,a[i]);
    }
    cout<<cnt;
    return 0;
}
