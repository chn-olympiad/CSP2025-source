#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[100005],b[100005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0){
            b[0]=a[0];
        }
        else{
            b[i]=b[i-1]^a[i];
        }
    }
    if(b[0]==k){
        ans++;
        for(int i=1;i<n;i++){
            if((k^b[i-1])==b[i]){
                    i++;
                    ans++;
            }
            for(int j=i+1;j<n;j++){
                if((k^b[i-1])==b[j]){
                    i=j+1;
                    ans++;
                    break;
                }
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            if((k^b[i-1])==b[i]&&i>=1){
                ans++;
                continue;
            }
            for(int j=i+1;j<n;j++){
                if((k^b[i-1])==b[j]){
                    i=j+1;
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

