#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],sum[N];
bool cmp(int x,int y){
    return x>y;
}
int ans=0;
int n;
void dfs(int x,int now,int step,int y,int s){
    if(step==y){
        if(a[x]*2<s){
                //cout<<x<<" "<<y<<" "<<s<<endl;
                ans++;
        }
        return ;
    }
    for(int i=now+1;i+(y-step-1)<=n;i++){
        if(s+(sum[n]-sum[i-1])<=2*a[x])break;
        dfs(x,i,step+1,y,s+a[i]);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        for(int j=3;j+i-1<=n;j++){
            dfs(i,i,1,j,a[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
