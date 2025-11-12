#include <bits/stdc++.h>
using namespace std;
const int N=1e6,Mod=998244353;
int a[N]={0},n;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long sum=1;
    for(int i=1;i<=n;i++){
        sum*=2;
    }
    long long cnt=0;
    for(sum-=1;sum>=0;sum--){
        long long zs=sum;
        int aa=0,bb=0,l=1;
        bool f=0;
        int xy=0;
        while(zs){
            l++;
            if(zs%2){
                xy++;
                if(f==0){
                    f=1;
                    aa=a[l];
                }
                else bb+=a[l];
            }
            zs/=2;
        }
        if(aa<bb&&xy>=3)cnt++;
    }
    cout<<cnt%Mod;
    return 0;
}
