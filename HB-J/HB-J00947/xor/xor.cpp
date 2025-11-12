#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int m,n,f[212101];
scanf("%d %d",&m,&n);
for(int i=1;i<=m;i++){
cin >> f[i];
}
int d;
if(m%n==0){
        d=m/n;
        cout << d<< endl;}
if(m%n>=0){
    d=m/n+1;
    cout << d << endl;
}
return 0;
}
