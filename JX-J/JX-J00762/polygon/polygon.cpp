#include<bits/stdc++.h>
using namespace std;
int a[501];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
int n,i,k,j,s,ans=0,xx,h,as;
cin>>n;
for(i=1;i<=n;i++){
cin>>a[i];
}
for(i=1;i<=n-2;i++){  xx=a[i];

    for(s=i+1;s<=n-1;s++){
    if(xx<a[s]) xx=a[s];
    for(h=s+1;h<=n;h++){as=a[i]+a[s];
    for(j=h;j<=n;j++){
        as=a[j]+as;
        if(xx<a[j]) xx=a[j];
    if(as>2*xx) {
            ans++;
            }
}
    }
    }
}
cout<<ans;
return 0;
}
