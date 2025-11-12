#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
using namespace std;
long long n,a[500005];
long long k;
bool f;
int a1,a0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        if(a[i]){
            a1++;
        }else{
            a0++;
        }
    }
    if(!a0){
        cout<<n/2;
    }else{
        int ans=0;
        if(k==1){
            for(int i=0;i<n;i++){
                if(a[i]==1&&a[i+1]==1){
                    ans++;
                    i++;
                }
            }
            if(ans=a1/2){
                ans--;
            }
            ans+=a0;
        }else{
            for(int i=0;i<n;i++){
                if(a[i]==1&&a[i+1]==1){
                    ans++;
                    i++;
                }
            }
            ans+=a0;
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
