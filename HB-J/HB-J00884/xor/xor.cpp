#include<iostream>
#include<cstdio>
using namespace std;
const int N=5e5+7;
int n,k;
int a[N],f=1,cnt1,cnt0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i])cnt1++;
        else cnt0++,f=0;
    }
    if(f)cout<<n/2;
    else{
        if(k)cout<<cnt1;
        else{
            int ans=0,cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i])cnt++;
                if(cnt==2)ans++,cnt=0;
                if(cnt==0&&a[i]==0)ans++;
            }
            cout<<ans;
        }

    }
    return 0;
}
