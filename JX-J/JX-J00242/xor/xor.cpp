#include<bits/stdc++.h>
using namespace std;
long long a,b,c,n,m,x[500005],k,t[500005],w[500005],zhi;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        long long sum=x[i],ji=0;
        for(int j=i;j<=n;j++){
            if(sum==k){
                zhi++;
                t[zhi]=i;
                w[zhi]=j;
                sum=0;
                ji++;
            }
            sum=sum^x[j+1];
        }
        a=max(a,ji);
    }
    cout<<a;

    return 0;
}
