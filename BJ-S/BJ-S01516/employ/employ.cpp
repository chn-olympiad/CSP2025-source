#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,m,a[100001]={},ans=0,cnt=0;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!a[i])
            cnt++;
    }
    for(int i=1;i<=n-cnt;i++){
        if(i==1)
            ans=1;
        ans*=i;
        ans%=998244353;
    }
    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
