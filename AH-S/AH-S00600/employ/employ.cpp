#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
string s;
int a[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(s.find("0")==-1){
        long long ans=1;
        for(int i=n;i>=1;i--){
            ans*=i;
            ans%=998244353;
        }
        cout<<ans;
    }else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
return 0;
}
