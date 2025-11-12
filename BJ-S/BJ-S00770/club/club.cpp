#include<bits/stdc++.h>
using namespace std;
int n;
int sum;
int new;
char a[][];
int max;
int main( ){
cin>>n;
for(int i=0;i<n;i++){
cin>>new;
cin>>a[3][i];
}
for(int i=1;i<=new/2;i++){
    if(a[1][i]>a[2][i]){
        if(a[1][i]>a[3][i]){
        max+=a[1][i];
        }else{
        max+=a[3][i];
        }
}else{
  if(a[2][i]>a[3][i]){
        max+=a[2][i];
        }else{
        max+=a[3][i];
        }
}
}
cout<<max;
return 0;
}