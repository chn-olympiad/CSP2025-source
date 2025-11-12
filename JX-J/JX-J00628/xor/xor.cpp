#include<bits/stdc++.h>
using namespace std;
int a[1000010],cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k<=1){
        for(int i=1;i<=n;i++){
            if(a[i]!=k){
                for(int j=i+1;j<=n;j++){
                    if(a[i]^a[j]==k){
                        cnt++;
                        i=j;
                        j=n+1;
                    }
                }
            }else{
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
