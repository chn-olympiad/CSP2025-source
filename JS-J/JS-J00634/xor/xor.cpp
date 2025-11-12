#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int k,n,a[100005],cnt=0;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    if(k==0){
        for(int i=0;i<n;i++){
            if(a[i]==0) cnt++;
            if(a[i]==1&&i!=n-1){
                  if(a[i]==a[i+1]){
                    cnt++;
                    i++;
                  }
            }
        }
    }
    if(k==1){
        for(int i=0;i<n;i++){
            if(a[i]==1) cnt++;
            if(a[i]==0&&i!=n-1){
                  if(a[i]==a[i+1]){
                    cnt++;
                    i++;
                  }
            }
        }
    }
    cout<<cnt;
    return 0;
}
