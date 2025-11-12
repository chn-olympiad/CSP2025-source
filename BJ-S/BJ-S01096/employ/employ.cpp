#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
string s;
int n,m,c[505],cnt,k;
long long cal(){
    long long base=1;
    for(int i=n;i>=n-k+1;i--){
        base=(base*i)%MOD;
    }
    return base;


}
int main(){

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]==0)cnt++;

    }
    int k=n-cnt;
    long long ans=cal();
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;




}



