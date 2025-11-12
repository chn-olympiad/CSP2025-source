#include<bits/stdc++.h>
using namespace std;
long long n,ans,mx;
int a[5010];
void dfs(int i,int x,int h){
    if(i==n){
        return;
    }
    if(x>=3&&h>mx){
        ans++;
        ans=ans%998244353;
        return;
    }
    int m=i;
    dfs(i++,x++,h+a[m]);
    return;
    dfs(i++,x,h);
    return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    mx=mx*2;
    sort(a+1,a+1+n);
    if((n==3&&a[1]+a[2]+a[3]<=mx)||n<3){
        cout<<0;
        return 0;
    }
    dfs(1,0,0);
    cout<<ans;
	return 0;
}
