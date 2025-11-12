#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,yn=1;
    cin>>n>>k;
    long long a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            yn=0;
        }
        else if(a[i]!=0&&a[i]!=1){
            yn=2;
        }
    }
    if(yn==1){
        cout<<k+(n-k)/2;
    }
    else if(yn==0){
        long long b[n+1],r=0,k2=k,s=0,va=0;
        for(long long i=1;i<=n;i++){
            if(a[i]==0||i==n){
                if(a[i]==1){
                    s++;
                }
                if(a[i]==0){
                    r++;
                }
                b[va]=s;
                va++;
                s=0;
            }
            else{
                s++;
            }
        }
        for(long long i=0;i<va;i++){
            if(k2>0){
                if(b[i]%2==1){
                    b[i]--;
                    k2--;
                    r++;
                }
            }
        }

        for(long long i=0;i<va;i++){
            if(k2>0){
                if(b[i]>=k2){
                    r+=k2;
                    b[i]-=k2;
                    k2=0;
                }
                else{
                    r+=b[i];
                    k2-b[i];
                    b[i]=0;
                }
            }
            else{
                r+=b[i]/2;
            }
        }
        cout<<r;
    }
    else{
        cout<<1;
    }
    return 0;
}
