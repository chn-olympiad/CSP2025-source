#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
cin>>a;
int n=a.length();
for(int i=0;i<n;i++){
    for(int j=0;j<n-i-1;j++){
        if(a[j+1]>a[j]) swap(a[j+1],a[j]);
    }
}
for(int i=0;i<n;i++){
    if(a[i]-'0'<=9 && a[i]-'0'>=0) cout<<a[i];
}
return 0;
}
