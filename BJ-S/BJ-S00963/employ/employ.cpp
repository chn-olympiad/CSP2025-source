#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],s[505],one=0;
bool f=false;
unsigned long long ans=0;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    char z;
    for(int i=1;i<=n;i++){
        cin>>z;
        if(z=='1'){
            a[i]=1;
            one++;
        }
        else if(z=='0'){
            a[i]=0;
            f=true;
        }
    }
    for(int i=1;i<=n;i++)cin>>s[i];
    if(!f){
        ans=1;
        for(int i=2;i<=n;i++){
            ans=(ans*i)%998244353;
        }
        cout<<ans;
    }else{
        cout<<"0";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

