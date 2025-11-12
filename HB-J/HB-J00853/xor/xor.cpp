#include<bits/stdc++.h>
using namespace std;
#define N 2*100000+5
#define ll long long
int n,k;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool o=true,w=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            o=false;
            if(a[i]!=0){
                w=false;
            }
        }
    }
    if(k==0&&o==true){
        cout<<n/2;
        return 0;
    }
    if(k<=1&&w==true){
        int ans=0;
        for(int i=1;i<=n-1;i){
            if(a[i]==1&&a[i+1]==1){
                ans++;i+=2;
                continue;
            }
            if(a[i]==0&&a[i+1]==0){
                ans++;i+=2;
                continue;
            }
            i++;
        }
        cout<<ans;
    }
    return 0;
}
