#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int nm=n*m;
int r,r1=0;

for(int i=1;i<=nm;i++)
    cin>>a[i];
int R=a[1];
sort(a+1,a+1+nm);
for(int i=nm;i>=1;i--){
    r1++;
    if(a[i]==R)
        r=r1;}
int n1=r/n+1;
cout<<n1<<' ';
int n2=r%n;
if(n1%2!=0){
    if(n2==0)
        cout<<n;
        else
            cout<<n2;
}
else{
    if(n2==0)
    cout<<1;
    else
        cout<<n-n2+1;
}
return 0;
}
