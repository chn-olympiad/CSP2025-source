#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }int sum=0;
    if(n==1){
        if(k==0){
            if(a[1]==0)sum++;
        }if(k==1){
            if(a[1]==1)sum++;
        }
    }if(n==2){
        if(k==0){
            if(a[1]==0)sum++;
            if(a[2]==0)sum++;
            if(a[1]==0&&a[2]==1||a[1]==1&&a[2]==0)sum++;
        }if(k==1){
            if(a[1]==1)sum++;
            if(a[2]==1)sum++;
        }
    }cout<<sum;
    return 0;
}

