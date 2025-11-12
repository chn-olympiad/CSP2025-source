#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[maxn],cnt1=0,f1=0,cnt2=0,f2=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)cnt1++;
        if(a[i]==0||a[i]==1)cnt2++;
    }
    if(cnt1==n)f1=1;
    if(cnt2==n)f2=1;
    if(f1==1){
        cout<<n/2;
    }else if(f2==1){
        if(k==0){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    cnt++;
                }
                if(a[i]==1&&a[i+1]==1){
                    cnt++;
                    i++;
                }
            }
            cout<<cnt;
        }else if(k==1){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    cnt++;
                }
            }
            cout<<cnt;
        }
    }
    return 0;
}
