#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
int n;
int k;
int s[N];
int cnt=0;
int sum=0;
signed main(){
    freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    int x=0;
    for(int i=1;i<=n;i++){
        int l=s[i]^s[x];
        if(l==k){
            cnt++;
            x=i;
        }



    }
    cout<<cnt;
    return 0;
}
//异或:^
