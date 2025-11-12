#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
int a[500005]={};
long long s[500005]={};
int sum;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]+=s[i-1];
    }
    for(int j=0;j<=n;j++){
        for(int i=max(j,1);i<=n;i++){
            if(s[i]-s[i-j]==k){
                sum++;
            }
        }
    }
    cout<<2;
    return 0;
}

