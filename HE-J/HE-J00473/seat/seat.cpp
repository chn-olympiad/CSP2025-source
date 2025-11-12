#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[105];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
cin>>a[i];
}
int x=a[1];
sort(a,a+n*m+1);
int sum=1;
for(int i=n*m;i>=1;i--){
if(a[i]==x){
x=sum;
break;
}
sum++;
}
int lie=(x+n-1)/n;
cout<<lie<<" ";
if(lie%2==0){
if(x%n==0) cout<<n-(x%n)-n+1;
else cout<<n-(x%n)+1;
}
else{
if(x%n==0) cout<<n-(x%n);
else if(x%n==1) cout<<n-(x%n)-n+2;
else cout<<n-(x%n)+n-2;
}
fclose(stdin);
fclose(stdout);
return 0;
}
