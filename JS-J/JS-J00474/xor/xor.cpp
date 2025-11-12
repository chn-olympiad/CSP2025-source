#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,cnt=0,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1) cnt++;
        }
    }
    else if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0) cnt++;
            else if(i<n&&a[i]==1&&a[i+1]==1){
                cnt++;
                i++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
