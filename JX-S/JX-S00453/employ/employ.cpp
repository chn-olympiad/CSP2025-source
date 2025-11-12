#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353,N=500;
int patient[N];
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string difficult;
    cin>>difficult;


    int num_of_0=0;
    for(int i=1;i<=n;i++){
        cin>>patient[i];
        if(patient[i]==0)num_of_0++;
    }
    sort(patient+1,patient+n+1,cmp);

    int len=difficult.length();
    bool f_1=true;
    for(int i=0;i<len;i++){
        if(difficult[i]=='0')f_1=false;
    }


    if(m==n){
        if(num_of_0>0){
            cout<<0;
            return 0;
        }
    }


    if(f_1){
        long long ans=1;
        for(int i=2;i<=n-num_of_0;i++){
            ans*=i;
            ans%=MOD;
        }
        for(int i=1;i<=num_of_0;i++){
            ans*=i;
            ans%=MOD;
        }
        int k=patient[n-m+1];
        long long ans2=1;
        for(int i=1;i<=n-num_of_0+k-1;i++){
            ans2*=i;
            ans2%=MOD;
        }
        ans+=ans2;
        ans%=MOD;
        cout<<ans;
        return 0;
    }

    return 0;
}
