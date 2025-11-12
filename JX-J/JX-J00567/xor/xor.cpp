#include<bits/stdc++.h>
using namespace std;
int n,k,maxn=-INT_MAX;
int a[500005];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            int ans=a[i];
            for(int g=i+1; g<=j; g++){
                ans=ans^a[g];
            }
            if(ans==k){
                cnt++;
            }
        }
    }
    cout<<cnt;

    return 0;
}