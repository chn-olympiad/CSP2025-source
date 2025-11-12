#include <iostream>
using namespace std;

int main(){
int n,k,a[100];
cin >> n >> k;
for (int i=1;i<=n;i++){
cin >> a[i];
}
for (int i=1;i<=n;i++){
if(i=n-k){
continue;
}
cout <<  a[i];
}
return 0;
}
