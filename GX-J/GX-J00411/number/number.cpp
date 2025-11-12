#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
char a[1000];
int n;
cin>>n;
for(int i=1;i<=n;i++){
cin>>a[i];
for(int j=1;j<=n;j++){
    if(a>a-1){
a[i]=a[i+1];
    }
}
}
cout<<a;
return 0;
}
