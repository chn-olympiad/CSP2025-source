#include <bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[101][101];
int main(){
freopen("seat1.in","r",stdin);
freopen("seat1.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>a[i][j];
    }
}
s=a[0][0];
sort(a,a+n*m);
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(a[i][j]==s){
            c=i;
            r=j;
            break;
        }
    }
}
cout<<c<<" "<<r;
return 0;
}
