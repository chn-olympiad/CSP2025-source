#include<bits/stdc++.h>
using namespace std;
const long long constant=998244353;
int n,a[5000],ans=0;
long long sum=0;
bool cmp(int x,int y){
    return x>y;
}
long long ride(int n){
    int ans=1;
    for(int i=2;i<=n;i++){
        ans*=i;
        ans%=constant;
    }
    return ans%constant;
}
long long dfs(int i,int maxium){
    int cnt=0;
    if(i==n-1&&sum>maxium){
        cout<<"++"<<endl;
        cnt++;
    }else{
        for(int j=i;j<n;j++){
            sum+=a[j];
            if(sum>maxium){ride(n-j)/ride(j)%constant;
                cnt+=(ride(n-j)/ride(j)%constant);
                continue;
            }else{
                cnt+=(dfs(j+1,maxium)%constant);
            }
            cnt%=constant;
            sum-=a[j];
        }
    }
    return cnt%constant;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n-2;i++){
        ans+=dfs(i+1,a[i])%constant;
    }
    cout<<ans;
    return 0;
}
