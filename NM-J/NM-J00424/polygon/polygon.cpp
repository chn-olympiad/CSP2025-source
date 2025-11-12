#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n=0,a[5005]={0},b=0,bi=0,co=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            b+=a[j];
            if(a[j]>bi) bi=a[j];
        }
        if(2*bi<=b) co+=1;
    }
    cout<<co;
    fclose(stdin);
    fclose(stdout);
}
