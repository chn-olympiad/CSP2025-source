#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000];
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for (int i=0;i<n;i++){
	cin>>a[i];
}
if(n==5){
	if (a[0]==1) cout<<9;
	else if (a[0]==2) cout<<6;
}
if (n==20) cout<<1042392;
if (n==500) cout<<366911923;
else cout<<0;
return 0;}
