#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int pt[550];
int sum[550];
int sum2[550];
long long num[550];
map<int,int>mp;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>pt[i];
        mp[pt[i]]++;
    }
    for(int i=n;i>=0;i--){
        sum2[i]=sum2[i+1]+mp[i+1];
        //cout<<num[i]<<" ";
    }
    for(int i=0;i<s.size();i++){
        char now=s[i];
        sum[i+1]=sum[i];
        if(now=='0'){
            sum[i+1]++;
        }
    }
    num[0]=1;
    for(int i=1;i<=n;i++){
        num[i]=num[i-1]*i%mod;
    }
    if(sum[n]==0){
        int num3=0;
        for(int i=1;i<=n;i++){
            num3+=mp[i];
        }
        cout<<num[num3]%mod;
    }else{
        long long ans=0;
        for(int i=1;i<=n-m+sum[n]-sum[n-m];i++){
                long long num1=1;
                int g=0;
                bool flag=1;
            for(int j=n;j>=1;j--){
                if(n-j<=i+g&&flag){
                    char x=s[j-1];
                    if(x=='0'){
                        g++;
                        num1*=n-(n-j);
                        num1%=mod;
                    }else{
                        if(sum2[0]-sum2[sum[j]]-(n-j)==1){
                         flag=0;
                        }
                        num1*=sum2[0]-sum2[sum[j]]-(n-j);
                        num1%=mod;
                    }
                }else{
                    num1*=sum2[sum[j]]-(n-j);
                    num1%=mod;
                }
            }
            ans+=num1;
            ans%=mod;
        }
        cout<<ans;
    }
    return 0;
}

