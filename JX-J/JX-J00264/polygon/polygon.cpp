#include<bits/stdc++.h>
using namespace std;
const long long N = 998244353;
int n,ls[5005],k[5005],a1=0;
long long ans=0;
long long jx(int y){
    long long sum = 1;
    for(int i=0;i<y;i++)
        sum *= (a1-i);
    sum %= N;
    for(int i=1;i<=y;i++){
        sum/=i;
    }
    return sum%N;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ls[i];
        if(ls[i])
            a1++;
    }
    sort(ls,ls+1+n);
    int ans = 0;
    for(int i=3;i<=a1;i++){
        ans += jx(i);
        ans %= N;
    }
    cout<<ans<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
