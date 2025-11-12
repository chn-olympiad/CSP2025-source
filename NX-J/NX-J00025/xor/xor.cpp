#include<bits/stdc++.h>
using namespace std;
long long num[100001],ans[100001];
int main(){
    freopen("xor3.in","r",stdin);
    freopen("xor3.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>num[i];
    }
    sort(num,num+n+1);
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            if(num[i]+num[j]==k||abs(num[i]-num[j])==k)
                {
                    if(num[i]!=0&&num[j]!=0)
                {
                    cout<<abs(num[i]-num[j])+1;
                    return 0;


        }
            }
        }
    }
}
