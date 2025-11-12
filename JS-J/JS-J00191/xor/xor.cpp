#include <bits/stdc++.h>
using namespace std;

long long n,k,a[500010],ans=0;
bool f=true;
int add(long long l,long long r){
    long long sum=0,cnt=0,cut=0;
    for(int i=l;i<=r;i++){
        cut=0;
        for (int j=i;j<=r;j++){
            sum=sum^a[j];
            if(sum==k){
                cut++;
                cut+=add(j+1,r);
                break;
            }
        }
        cnt=max(cnt,cut);
    }
    return cnt; 
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (long long i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]>1)
            f=false;
    }
    if(k==0){
        for (long long i=1;i<=n;i++){
            if(a[i]==0)
                ans++;
        }
    }
    else if(f){
        for (long long i=1;i<=n;i++){
            if(a[i]==1)
                ans++;
        }
    }
    else {
        long long l=1;
        for (long long i=1;i<=n;i++){
            if(a[i]==k){
                ans+=add(l,i-1);
                ans++;
                l=i+1;
            }
        }
        ans+=add(l,n);
    }
    cout << ans << "\n";
    return 0;
}