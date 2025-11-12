#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
int i,m,n,j,k,s,h,ans=0;
cin>>n>>k;
for(i=1;i<=n;i++){
    cin>>a[i];
}
for(i=1;i<=n;i++){
        h=0;
        int q=0;
        while(h+i<=n){
    q=q^a[i+h];
    if(q==k) {
            i=i+h;
            ans++;
            break;
        }
        h++;
    }
}
cout<<ans;

return 0;
}



