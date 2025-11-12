#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
    cin>>a[i];}
    for(int i=2;i<=m*n;i++){
    if(a[i]>a[1]){sum++;}
    }
    cout<<sum/m<<" "<<sum%n+1;
    return 0;
}
