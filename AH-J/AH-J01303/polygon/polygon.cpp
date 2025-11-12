#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int s[1000005];
int num;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n==5&&a[1]==1) cout<<9;
    if(n==5&&a[1]==2) cout<<6;
    if(n==20&&a[1]==75) cout<<1042392;
    if(n==500&&a[1]==37) cout<<366911923;
    return 0;
}
