#include<bits/stdc++.h>
#define N 550
#define mod 998244353
#define int long long
using namespace std;
int s[N];
int a[N];
int c[N];
int cnt[N];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=n;i++){
        char p;
        cin>>p;
        s[i]=p-'0';
        a[i]=i;
        if(s[i]==0)flag=0;
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        cnt[c[i]]++;
    }
    int h=1;
    for(int i=1;i<=n;i++){
        h*=i;
        h%=mod;
    }
    if(flag==1){
        cout<<h<<endl;
        exit(0);
    }else if(m==1){
        int ans=1;
        int ccnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]==1)ccnt++;
        }
        for(int i=1;i<=n-ccnt;i++){
            ans*=i;
            ans%=mod;
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=cnt[i-1];
            if(s[i]==1){
                ans*=sum;
                sum--;
                ans%=mod;
            }
        }
        int ans1=1;
        for(int i=1;i<=n;i++){
            ans1*=i;
            ans1%=mod;
        }
        cout<<(ans1+mod-ans)%mod<<endl;
    }else if(m==n){
        bool flag=1;
        for(int i=1;i<=n;i++){
            if(s[i]==0)flag=0;
        }
        if(flag==1){
            int ans=1;
            for(int i=1;i<=n;i++){
                ans*=i;
                ans%=mod;
            }
            cout<<ans<<endl;
        }else{
            cout<<0<<endl;
        }
    }else{
        int cnt=0;
        do{
            int p=0;
            for(int i=1;i<=n;i++){
                if(c[a[i]]<=p||s[i]==0){
                    p++;
                }
            }
            if(n-p>=m)cnt++;
        }while(next_permutation(a+1,a+1+n));
        cout<<cnt%mod<<endl;
    }
    return 0;
}
