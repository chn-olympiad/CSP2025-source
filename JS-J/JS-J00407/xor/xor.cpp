#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
long long a[MAXN];
long long xxor(long long a,long long b){
    long long ans=0;
    long long i=0;
    while(a>0||b>0){
        if(a%2!=b%2)
            ans=(1<<i)+ans;
        b>>=1;
        a>>=1;
        i++;
    }
    return ans;
}
long long plus_xor(long long l,long long r){
    long long ret=a[l];
    for(int i=l+1;i<=r;i++)
        ret=xxor(ret,a[i]);
    return ret;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];


    int cnt=0;
    int now=0;
    while(now<n){
        bool finded=0;
        for(int j=now+1;j<=n;j++){
            if(a[j]==k){
                finded=1;
                cnt++;
                now=j;
                break;
            }
            for(int i=now+1;i<=j;i++){
                if(plus_xor(i,j)==k){
                    finded=1;
                    cnt++;
                    now=j;
                    break;
                }
            }
            if(finded) break;
        }
        if(!finded) break;
    }
    cout<<cnt;
    return 0;

}
