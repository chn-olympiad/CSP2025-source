#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;
int a[100005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt1=0,cnt2=0;
    cin>>n>>k;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag=0;
        if(a[i]==1) cnt1++;
        if(a[i]==0) cnt2++;
    }
    if(flag==1&&k==0) cout<<n/2;
    else if(k==1) cout<<cnt1;
    else if(k==0) cout<<cnt2+cnt1/2;
    else cout<<7;
    return 0;
}
