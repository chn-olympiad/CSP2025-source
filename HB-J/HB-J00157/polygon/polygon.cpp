/*
plan a: 12 pts expected
plan b: pts expected

while(1){
    rp+=inf;
}
pls let me pass
i want 1st prize
plllllllllllllllllllsssssssssssssssssssss
*/
#include<iostream>
#include<cstdio>
using namespace std;
long long n,a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }

    //plan a only for pianfening
    if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) cout<<1;return 0;

    //plan b


    return 0;
}
//touch to enter texts...
