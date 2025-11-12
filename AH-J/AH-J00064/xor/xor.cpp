#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 100;
int n;
int k;
int a[N];
long long vis[N];
long long ans;
long long main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(long long len = 1;len<=n;len++){
        long long l = 1;
        long long r = len+l-1;
        long long cnt = 0;
        long long temp = a[l];
        for(long long i = l;i<=r;i++){
            if(vis[i] == 1){
                cnt++;
            }
            if(i != 1){
                temp ^= a[i];
            }
        }
        while(r <= n){
            if(cnt == 0 && temp == k){
                for(long long i = l;i<=r;i++){
                    vis[i] = 1;
                }
                l = r+1;
                r = len+l-1;
                ans++;
                if(r <= n){
                    temp = a[l];
                    for(long long i = l+1;i<=r;i++){
                        temp ^= a[i];
                    }
                }
            }else{
                l++;
                r++;
                cnt -= vis[l-1];
                cnt += vis[r];
                temp ^= a[l-1];
                temp ^= a[r];
            }
        }
    }
    cout<<ans;



    return 0;
}
