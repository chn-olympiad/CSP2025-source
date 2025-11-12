#include<bits/stdc++.h>
using namespace std;
int a[100005]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
    int ans=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int fan=1;
    int sum;
    while(fan<=n){
        for(int i=0;i<n+1-fan;i++){
                sum=a[i];
            for(int j=i+1;j<i+fan;j++){
                sum^=a[j];
            } 
            if(sum==k){
                ans++;
            }
        }
        fan++;
    }
    cout<<ans;
return 0;
}
