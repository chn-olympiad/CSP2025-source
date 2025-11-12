#include<bits/stdc++.h>
using namespace std;
int main(){

freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,n1,m1;
int s=1;
cin>>n>>m;
int r,t,q,w;
int z=n*m;
int l=z+2;
int b[n][m];
int a[109];
for(int i=1;i<=z;i++){
    cin>>a[i];
r=a[1];
}
if(n=1&&m=1){
    cout<<1<<1;
    return 0;
}

sort (a+1,a+z+1);
for(int i=1;i<=z;i++){
    if(a[i]==r)
        t=i;
}
int d[l];

for(int j=1;j<=z;j++){
    n1=1;
    m1=1;

    d[j]=b[n1][m1];
if(n1==n&&m1%2==1)
    m1++;
if(m1%2==1)
    n1++;
    continue;
if(n1==1&&m1%2==0)
    m1++;
if(m1%2==0)
    n1--;
    continue;


}for(int i=1;i<=n;i++){
for(int j=1;j<=m;j++){

       if(b[i][j]==d[t])
            q=i;
            w=j;

          }}
          cout<<w<<" "<<q;
return 0;
}
