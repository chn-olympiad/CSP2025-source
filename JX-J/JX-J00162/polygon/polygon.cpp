#include <iostream>
using namespace std;
int main(){
int n,a[5002];
cin >> n;
if(n>3){
      for (int i=1;i<=n;i++){
cin >> a[i];
}
for (int i=1;i<=n;i++){
cout << a[i];
}
}
if(n==3){
    cout << 1;
}
return 0;
}
