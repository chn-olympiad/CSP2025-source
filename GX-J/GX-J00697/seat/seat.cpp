#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,s[1001],sum=1,c,r;
    cin>>n>>m>>s[0];
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
        if(s[0]<s[i]){
        sum++;
        }
    }
    if(sum<=n){
        c=1;
        r=sum;
    }
    for(int j=1;j<=1001;j++){
        if(sum<=n*j){
            c=j;
            if(j%2==0){
                r=n+1-[sum-n*(j-1)];
            }
            else{
                r=sum-n*(j-1);
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
