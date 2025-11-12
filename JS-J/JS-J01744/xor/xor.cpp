#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,l,r,ans;
int a[500005];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }

    int last = 0;
    while(l<=n){
        bool f = 0;
        int rmin=n;
        l = last++;
        r=l;
        int num=a[l];
        while(n){
            if(num==k){
                rmin = min(rmin,r);
                ans++;
                last = r;
                break;
            }
            else{
                r++;
                num = (num^a[r]);
                if(num==k){
                    rmin = min(rmin,r);ans++;last = r;
                }
            }

            if(l==n){
                f = 1;
                break;
            }
            if(l==rmin){
                last = r;
                break;
            }
            else if(r==rmin){
                l++;
                r=l;
                num = a[l];
            }

            if(l==n){
                f = 1;
                break;
            }

            if(l==rmin){
                last = l;
                break;
            }


        }
        if(f){
            cout<<ans;
            return 0;
        }

    }

    return 0;
}
