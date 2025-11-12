#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
long long n;
long long m;
int a[999];
cin>>n>>m;
for(int i=1;i<=n*m;i++){
    cin>>a[i];
    sort(a[i],a[i+1]);
}
for(int i=0;i<n*m;i++){
    cout<<a[i];
}


return 0;
}
