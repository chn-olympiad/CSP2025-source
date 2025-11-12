#include<bits/stdc++.h>
using namespace std;
int n,a[4],sum,zd;
bool b[5005];

int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
if(n==3){
    if(a[1]+a[2]>=a[3]&&a[2]+a[3]>=a[1]&&a[1]+a[3]>=a[2])sum=1;
}
    cout<<sum;
    
    return 0; 
}

