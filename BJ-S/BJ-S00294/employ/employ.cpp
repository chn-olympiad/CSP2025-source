#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=505;
const int mod=998244353;
int a[MAXN];
int f[MAXN];
int cnt;
int nd[MAXN];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int sum1=n;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            sum1--;
        }
    }
    if(sum1<m){
        cout<<0;
        return 0;
    }
    if(sum1==n){
        int sum=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                sum++;
            }
        }
        if(n-sum<m){
            cout<<0;
            return 0;
        }
        int ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=mod;
        }
        cout<<ans;
        return 0;
    }
    int need=1;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            need++;
        }
        if(s[i]=='1'){
            f[++cnt]=i;
            nd[cnt]=need;
        }
    }
    sort(nd+1,nd+cnt+1,greater<int>());
    int ans=0;
    int base=1;
    for(int i=1;i<=n-m;i++){
        base=base*i%mod;
    }
    for(int s=(1<<m)-1;s<=(1<<cnt)-1;s++){
        int sum_1=0;
        int ss=s;
        while(ss){
            if(ss&1){
                sum_1++;
            }
            ss=ss/2;
        }
        if(sum_1!=m){
            continue;
        }
        int res=1;
        int left=0;
        for(int i=1;i<=cnt;i++){
            if(s&(1<<(i-1))!=0){
                int j;
                for(j=1;j<=n;j++){
                    if(a[j]>=nd[i]){
                        break;
                    }
                }
                res*=(n-j+1-left);
                res=res%mod;
                left++;
            }
        }
        ans=(ans+res*base%mod)%mod;
    }
    cout<<ans;
}
