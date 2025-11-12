#include<bits/stdc++.h>
using namespace std;
long long a[5005];
bool f[5005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,s,max,ans=0;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    for(long long i=3;i<=n;i++){
        for(long long j=0;j<n;j++){
            f[j]=false;
        }
        for(long long j=0;j<i;j++){
            f[j]=true;
        }
        do{
            max=-1;
            s=0;
            for(long long j=0;j<n;j++){
                if(f[j]==true){
                    s+=a[j];
                    if(max<a[j]){
                        max=a[j];
                    }
                }
            }
            if(s>max*2){
                ans++;
                if(ans>=998244353){
                    ans%=998244353;
                }
            }
        }while(prev_permutation(f,f+n));
    }
    cout<<ans<<endl;
    return 0;
}
