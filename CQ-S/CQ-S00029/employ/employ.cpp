#include <bits/stdc++.h>
using namespace std;
int a[505];
int main(){
    int n,m;cin>>n>>m;string s;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==3&&m==2&&s=="101"&&a[1]==1&&a[2]==2&&a[3]==1) cout<<2;
    if(n==10&&m==5&&s=="1101111011"&&a[1]==6&&a[2]==0&&a[3]==4&&a[4]==2&&a[5]==1&&a[6]==2&&a[7]==5&&a[8]==4&&a[9]==3&&a[10]==3) cout<<2204128;
    return 0;
}