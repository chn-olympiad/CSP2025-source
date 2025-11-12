#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int a[1000000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.in","w",stdout);
    int n;
    cin>>n;
    if(n<=3){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        if(a[1]+a[2]>a[3]){
            cout<<1<<endl;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    else{
        bool ok=true;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]!=1){
                ok=false;
            }
        }
        if(ok){
            long long sum=0;
            long long cnt=1;
            for(int j=1;j<=n;j++){
                cnt*=j%N;
            }
            for(int i=3;i<=n;i++){
                long long cnt1=1,cnt2=1;
                for(int j=1;j<=i;j++){
                    cnt1*=j%N;
                }
                for(int j=1;j<=n-i;j++){
                    cnt2*=j%N;
                }
                sum+=cnt/(cnt1*cnt2%N)%N;
            }
            cout<<sum;
            return 0;
        }
        else{
            long long sum=0;
            long long cnt=1;
            for(int j=1;j<=n;j++){
                cnt*=j%N;
            }
            for(int i=3;i<=n;i++){
                long long cnt1=1,cnt2=1;
                for(int j=1;j<=i;j++){
                    cnt1*=j%N;
                }
                for(int j=1;j<=n-i;j++){
                    cnt2*=j%N;
                }
                sum+=cnt/(cnt1*cnt2%N)%N;
            }
            cout<<sum;
            return 0;
        }
    }
    return 0;
}
