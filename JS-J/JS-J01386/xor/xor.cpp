#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
int k;
cin>>n>>k;
int a[n];
for(int i=0;i<n;i++){
cin>>a[i];
}
int m=-1;
for(int i=0;i<n;i++){
for(int x=i+1;x<n;x++){
    int s1=a[0];int s2=a[n-1];
for(int j=1;j<=i;j++){
s1^=a[j];
}
for(int j=n-2;j>i;j--){
s2^=a[j];
}
if(s1==k&&s2==k){
m=max(m,max(i+1,n-x-1));
}
}
}
cout<<m;
return 0;
}
