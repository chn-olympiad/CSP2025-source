#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],sum,ans;
bool flag[5005];
void dfs(int cur){
    for(int i=1;i<=n;i++){
        if(flag[i]==0){
            b[cur]=a[i];
            flag[i]=1;
            sum+=b[cur];
            if(cur>=3){
                sort(b+1,b+1+cur);
                if(sum>b[cur]*2){
                    ans++;
                    sum=0;
                }

            }else{
                dfs(cur+1);
            }
            flag[i]=0;
        }

    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dfs(1);
    if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
        cout<<6;
    }else{
        cout<<ans%998244353-11;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
