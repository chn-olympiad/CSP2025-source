#include<bits/stdc++.h>
using namespace std;
long long m,k[101],seat,x,ci=0,hang,lie;
double n;
int main(){
    freopen("seat.out","w",stdout);
    freopen("seat.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>x;
        k[x]++;
        if(i==1){
            seat=x;
        }
    }
    for(int i=101;i>=1;i--){
        if(k[i]!=0){
            if(i==seat) break;
            else ci++;
        }
    }
    lie=ceil(ci/n);
    if(lie%2==0){
        hang=m-(ci%int(n))+1;
    }
    else{
        if(ci<=int(n)) hang=ci;
        else hang=ci%int(n);
        if (hang==0) hang=n;
    }
    cout<<lie<<" "<<hang;
    return 0;
}

