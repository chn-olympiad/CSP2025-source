#include<bits/stdc++.h>
using namespace std;
// NOTE (NOI#1#): HELLO
int a[100001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt+=a[i];
    }
    sort(a,a+n);
    for(int l=0;l<n;l++){
        for(int r=l;r<n;r++){
            if(r-l>n-3){
                continue;
            }
            int h=0;
            for(int i=l;i<=r;i++){
                    h+=a[i];
            }

            if(r!=n-1){
                if(cnt-h>2*a[n-1]){
                    ans++;
                    ans%=998244353;
                }
            }else{
                if(cnt-h>2*a[l-1]){
                    ans++;
                    ans%=998244353;
                }
            }
        }
    if(cnt>a[n-1]*2){
        ans++;
    }
    cout<<ans%998244353;
    return 0;
}
