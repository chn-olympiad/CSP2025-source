#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5010;
const int P=998244353;
int n,ans;
int a[N];
int cnt,cnt1;

void dfs(int dep,int sum,int mx,int num){
    if(dep>n){
        if(num>=3&&sum>2*mx){
            ans=(ans+1)%P;
            cnt++;cnt1++;
            if(cnt>100000000){
                cerr<<dep<<" "<<sum<<" "<<mx<<" "<<num<<":"<<ans<<" "<<cnt1<<endl;
                cerr<<ans<<endl;
                cnt=0;
            }
        }
        return;
    }
    dfs(dep+1,sum+a[dep+1],max(mx,a[dep+1]),num+1);
    dfs(dep+1,sum,mx,num);
    return;
}

signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,0,0);
    cout<<(ans/2)%P<<endl;
    fclose(stdin);fclose(stdout);
    return 0;
}