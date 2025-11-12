#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[50005];
int sum[3];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k>1)return 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>1){
            return 0;
        }else{
            sum[a[i]]++;
        }
    }
    if(k==0&&sum[0]==0){
        cout<<n/2;
        return 0;
    }
    if(k==0){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==1&&a[i+1]==1){
                cnt++;
                i++;
            }
        }
        cout<<cnt+sum[0];
    }else{
        cout<<sum[1];
    }
    return 0;
}
