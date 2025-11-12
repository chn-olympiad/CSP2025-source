#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,a[5005];
bool k;
long long jf=0;
void dfs(int x,int y,int z,int q){
    if(x>n){
        return ;
    }
    if(y==1&&z>=3&&a[x]*2<q){
        jf++;
        jf%=998244353;
    }
    dfs(x+1,1,z+1,q+a[x+1]);
    dfs(x+1,0,z,q);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            k=1;
        }
    }
    sort(a+1,a+1+n);
    if(k==0){
        long long sum=1,cnt=0;
        for(int i=3;i<=n;i++){
            for(int j=n;j>=n-i+1;i--){
                sum*=j;
            }
            for(int j=1;j<=i;j++){
                sum/=j;
            }
            sum%=998244353;
            cnt+=sum;
            sum=1;
            cnt%=998244353;
        }
        cout<<cnt;
    }else{
        dfs(0,0,0,0);
        cout<<jf;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
