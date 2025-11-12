#include <iostream>
#include <string>
using namespace std;
int arr[1000005];
//int brr[12][12];
int main(){

freopen("number.cpp","r",stdin);
freopen("number.cpp","w",stdout);
string a;
cin>>a;
int d=0;
int l=a.size();
for(int i=0;i<l;i++){
if(a[i]>='0'&&a[i]<='9'){
arr[d]=a[i]-48;
d++;
}



}
for(int i=0;i<l;i++){

for(int j=i+1;j<l;j++){
if(arr[j]>arr[i]){
int b=arr[i];
arr[i]=arr[j];
arr[j]=b;
}
}
}
for(int i=0;i<l;i++){
cout<<arr[i];
}

return 0;
}
