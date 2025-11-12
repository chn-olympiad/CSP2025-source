#include<bits/stdc++.h>
using namespace std;
int n,a[50010];
long long k,ans=0;

bool abc(int l,int r){
    long long h=a[l];
    for(long long i=l+1;i<=r;i++){
        h=(h^a[i]);
    }
    if(h==k){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int j;
    for(int i=1;i<n;i=j+1){
        for(j=i;j<=n;j++){
            if(abc(i,j)==1){
                ans++;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}

