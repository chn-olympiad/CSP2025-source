#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,num=0,j,x,y,l=0;
    cin>>n>>k;
    long long a[n],i=0,b[100][2];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    j=1;l=0;
    for(x=0;x<n;x++){
        for(y=x;y<n;y++){
            for(i=x;i<=y;i++){
                j=j&&a[i];
            }
            if(j==k){
                b[l][0]=x;
                b[l][1]=y;
                l++;
            }
        }
    }
    cout<<l;
    return 0;
}
