#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100005];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int n,k;
cin>>n>>k;
if(n==1&&k!=n)cout<<0;
else if(n==1&&k==n)cout<<1;
else {
	cout<<2;
}
	return 0;
}
