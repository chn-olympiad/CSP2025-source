#include<bits/stdc++.h>
using namespace std;
int n,k,arr[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int cnt=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        if(arr[i]==k) cnt++;
        else{
            int sum=arr[i];
            for(int j=i+1;j<=n;j++){
                sum=sum^arr[j];
                if(sum==k){
                    cnt++;
                    i=j+1;
                    break;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
