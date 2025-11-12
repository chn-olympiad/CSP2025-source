#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int m;
int f[1923];
cin >> m;
for(int i=1;i<=m;i++){
cin >>f[i];
}
int p=m*2-2;
cout << p << endl;
return 0;
}
