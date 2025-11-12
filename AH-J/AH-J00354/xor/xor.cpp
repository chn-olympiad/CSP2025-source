#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
int n,k,cnt;
int a[N],t;
signed main(){
ios::sync_with_stdio(0);
cin.tie(0);
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;

for(int i=1;i<=n;i++){
    cin>>t;
    a[i]=a[i-1]^t;
}
int p=0,i=0,q=0;
for(i=1;i<=n;){
        bool flag=1;
    for(p=i;p<=n&&flag;++p){
        for( q=p;q>=i&&flag;--q){
        if(a[p]^a[q-1]==k){
            flag=0;
            ++cnt;
        }
        }
    }
    i=p;
}
cout<<cnt;
return 0;
}
