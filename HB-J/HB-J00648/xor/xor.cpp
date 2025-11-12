#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
long long k;
int n,ans;
int a[600000]={0};
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            ans++;
            cnt=0;
        }
        else{
            cnt++;
            if(cnt==2&&k==0){
                ans++;
                cnt=0;
            }
        }
    }
    cout<<ans;
    return 0;
}


