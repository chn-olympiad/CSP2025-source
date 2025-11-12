#include <bits/stdc++.h>
using namespace std;
const int N=5000;
const int M=998244353;
int n;
int a[N],t[N],ans,sum,num=3;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=l+num-1;
    for(int i=1;i<=n;i++){
        for(int j=l;j<=r;j++){
            sum+=a[j];
            t[j]=a[j];
        }
        sort(t+l,t+r+l);
        if(sum>t[r]*2) ans++;
        if(r==n&&l==(r-num+1)){
            num++;
            l=1;
            r=l+num-1;
        }
        else{
            if(r==n){
                l++;
                r=l+num-1;
            }
            else{
                r++;
                l++;
            }
        }
    }
    cout<<ans%M;
    return 0;
}
