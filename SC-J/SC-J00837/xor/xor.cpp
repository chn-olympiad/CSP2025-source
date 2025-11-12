#include<bits/stdc++.h>
using namespace std;
int n,s;long long a[500001];
int main(){
//freopen("xor.in","r",stdin);
//freopen("xor.out","w",stdout);
for(int i=1;i<=n;i++){
	cin>>a[i];s^=a[i];}
cout<<s%10000;
return 0;}