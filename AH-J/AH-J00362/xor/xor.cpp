#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[11451491];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k<=1){
        if(k==0){
            int zero=0;
            int one=0;
            for(long long i=1;i<=n;i++){
                cin>>a[i];
                if(a[i]==1)one++;
                else zero++;
            }
            if(zero==0)cout<<n/2;
            else{
                int cnt=0;
                for(long long i=1;i<=n;i++){
                    if(a[i]==1&&a[i+1]==1){
                        cnt++;
                        i++;
                    }
                }
                cout<<cnt+zero;
            }
        }
        else if(k==1){
            int zero=0;
            int one=0;
            for(long long i=1;i<=n;i++){
                cin>>a[i];
                if(a[i]==1)one++;
                else zero++;
            }

            cout<<one;
        }
    }
    return 0;
}
