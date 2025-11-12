#include<bits/stdc++.h>
using namespace std;
int l,r,a[100010],k,n,sum,res;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    if(n<=k&&k==0){
        cout<<0;
    }
    return 0;
    }
