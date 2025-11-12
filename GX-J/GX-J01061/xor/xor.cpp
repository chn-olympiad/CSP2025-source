#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,a[500010],sum=0,ans=0,j=-1;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]=a[i]&2;
    }
    for(int i=j+1;i<n;i++){
        for(j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                sum+=a[k];
            }
            if(sum==k){
                ans++;
                sum=0;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
