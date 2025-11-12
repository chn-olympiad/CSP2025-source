#include<bits/stdc++.h>
using namespace std;
long long m,n,k,l,a[1000001],s[1001][1001];
bool b=1;
int main(){
   cin>>n>>k;
    for(int i=1;i<=n;i++){cin>>a[i];if(a[i]!=1) b=0;}
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
if(b&&k==0) cout<<n/2;
else{
    if(k==1){for(int i=1;i<=n;i++){if(a[i]==1) m++;}}
    else{
            for(int i=1;i<=n+1;i++){
        if(a[i]==0){
        m++;
        m+=l/2;
        l=0;
        }
        if(a[i]==1)l++;
            m--;
            }

    }
    cout<<m;
    }
}
