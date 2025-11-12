#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[300001];
long long ans=0;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);

cin>>n>>m;
for(long long i=1;i<=n;i++ ){
    cin>>a[i];
}
for(long long i=1;i<=n;i++){
    long long k=0;
    for(long long j=i;j<=n;j++){
            k=k|a[j];

        if(k==m){
            ans++;
            i=j;
            k=0;
            break;
        }
    }
}
cout<<ans;
return 0;

}
