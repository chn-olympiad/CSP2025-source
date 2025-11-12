#include<bits/stdc++.h>
using namespace std;
const int N = 5000;
int a[N+3],n,ans[N+3],nn,vis[N+3];
long long cnt = 0;
bool check(int k){
   // cout<<ans[k-1]<<endl;
    long long sum = 0;
    for(int i = 1;i < k;i++){
        if(sum > 2*ans[k-1])return 1;
        sum+=ans[i];
    }
   // cout<<sum<<endl;
    if(sum > 2*ans[k-1])return 1;
    return 0;
}
void dfs(int m,int k){
    if(m == 0 && k == nn+1){
            //for(int i =1;i < k;i++){
            //    cout<<ans[i]<<" ";
            //}
            //cout<<endl;
        if(check(k)){
           // cout<<"------";
            //for(int i =1;i < k;i++){
            //    cout<<ans[i]<<" ";
            //}
            //cout<<endl;
            cnt++;
            cnt %= 998244353;
        }
        return;
    }
    for(int i = k;i <= n;i++){
        if(vis[i])continue;
        if(ans[k-1] > a[i])continue;
        ans[k] = a[i];
        vis[i] = 1;
        dfs(m-1,k+1);
        vis[i] = 0;
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);//cin>>n;
    for(int i = 1;i <= n;i++)scanf("%d",&a[i]);//cin>>a[i];
    sort(a+1,a+1+n);
    for(int i = 3;i <= n;i++){
        nn = i;
        dfs(i,1);
    }
    printf("%lld",cnt);//cout<<cnt<<endl;
	return 0;
}
