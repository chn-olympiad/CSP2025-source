#include<bits/stdc++.h>
using namespace std;
int n,arr[5003],cnt=0;
int f(int x){
    int ans=0;
    while(x!=0){
        ans+=x;
        x--;
    }
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            for(int k=j+1;k<=n;k++){
                int ch=n-j;
                sum+=f(ch);
            }
        }
    }
    cout<<sum%998244353;
    return 0;
}
