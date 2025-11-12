#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5050],s[5050],p=988244353,cnt=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    stable_sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            if(s[j]-s[i-1]>a[j]) cnt=(cnt+1)%p;
        }
    }cout<<cnt;
    return 0;
}
