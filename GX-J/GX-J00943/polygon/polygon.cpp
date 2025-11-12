#include <bits/stdc++.h>
using namespace std;
int n,s,x,z;
int a[101];
int main(){
freopen("polygon1.in","r",stdin);
freopen("polygon1.out","w",stdout);
cin>>a;
for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]>x){
        x=a[i];
    }
}
for(int i=0;i<n;i++){
    z=0;
    for(int j=0;j<n;j++){
        z+=a[j];
    }
    if(z>x*2){
        s++;
    }

}
cout<<s;
return 0;
}
