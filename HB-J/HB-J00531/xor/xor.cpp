#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,k,cnt;
int a[N];
int prex[N];
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    prex[1]=a[1];
    for(int i=2;i<=n;i++){
        prex[i]=prex[i-1]^a[i];
    }
    if(n<=N&&k<=1){
        for(int i=1;i<n;i++){
            if(a[i]==k)
                cnt++;
            else if(a[i]^a[i+1]==k){
                cnt++;
                i++;
            }
        }
    }
    else {
        while(l<=r){
            int l=1,r=2;
            if(a[l]==k){
                cnt++;
                l++;r++;
                continue;
            }
            if(a[l]^a[r]==k){
                cnt++;
                l=r+1;r=l+1;
                continue;
            }
            else{
                int x=a[l]^a[r];
                for(int j=r+1;j<=n;j++){
                    if(x^a[j]==k){
                        cnt++;
                        l=j+1;r=l+1;
                    }
                }
            }

        }

    }
    cout<<cnt;
    return 0;
}

