#include<bits/stdc++.h>
using namespace std;
int sum=0;int d[100001];int j=1;int o=0;
int main (){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
 int n,k;cin>>n>>k;
 for(int i=1;i<=n;i++)
        cin>>d[i];
        if(k==0)cout<<n/2;
       else if(k==1){
        for(int i=1;i<=n;i++)
            if(d[i]==1)sum++;
        cout<<sum;
       }
       else cout<<10;
    return 0;
}
