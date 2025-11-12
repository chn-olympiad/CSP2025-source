#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
long long n,m,s,z;
cin>>n>>m;
long long a[100005],b[1000][1000],c[100005];
for(int i=1;i<=n*m;i++){
cin>>a[i];
}
s=a[1];
sort(a+1,a+n*m+1);
for(int i=n*m;i>=1;i--){
c[n*m-i+1]=a[i];
}
for(long long i=1;i<=n;i++){
for(long long j=1;j<=m;j++){
if(j%2==1)b[i][j]=c[(j-1)*n+i];
else b[i][j]=c[j*n-i+1];
if(b[i][j]==s){
cout<<j<<" "<<i;
break;
}

}
}
return 0;
}

