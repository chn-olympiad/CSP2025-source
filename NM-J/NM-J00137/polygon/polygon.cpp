#include<bits/stdc++.h>
using namespace std;
int n,big=0,num=0,k=0;
const int N=5010;
int a[N];
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
int main(){
cin>>n;
for(int i=0;i<n;i++){
	cin>>a[i];
}
if(n==3){

if(a[1]+a[2]+a[0]>2*max(a[0],max(a[1],a[2])))cout<<1;
else cout<<0;
}
if(n<3)cout<<0;
return 0;
}

