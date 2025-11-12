#include <bits/stdc++.h>
using namespace std;
int n,m;
int cnt,ans;
int c,r;
int a[10][10];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>a[i][j];
        if(a[1][1]<a[i][j])cnt++;
    }
}
ans=cnt+1;
if(ans%n==0)c=ans/n;
if(ans%n!=0)c=ans/n+1;
if(c%2!=0)r=ans-((c-1)*n);
if(c%2==0)r=n-(ans-((c-1)*n))+1;

cout<<c<<r;
return 0;}
