#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int a[maxn];
int main(){
    freopen("xor4.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1,r=1,sum=0,cnt=0;
    for(int i=1;i<=n;i++){
            if(a[i]==k){
                cnt++;
                sum=0;
                r++;
                l=r;
            }
        sum+=a[r]^a[r-1];
        r++;
        if(sum>k){
            l++;
            sum-=a[l]^a[l-1];
        }
        if(sum==k){
            r++;
            l=r;
            sum=0;
            cnt++;
        }
        if(r>n)break;
    }
    cout<<cnt;
    return 0;
}
