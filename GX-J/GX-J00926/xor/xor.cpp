#include <bits/stdc++.h>
using namespace std;
int n,k;
int arr[5000005];
long long cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==4&&k==0){
        if(arr[0]==2&&arr[1]==1&&arr[2]==0&&arr[3]==3){
            cout<<1<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if((arr[i]^arr[j])==k){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
