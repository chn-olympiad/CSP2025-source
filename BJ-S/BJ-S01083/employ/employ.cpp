#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
long long a[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    if(s.find('1')==-1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long sum=0;
    for(int i=1;i<=n;i++){
        long long cnt=1;
        for(int j=0;j<i;j++){
            cnt*=(n-j);
        }
        sum+=cnt;
        sum%=mod;
    }
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
