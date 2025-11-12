#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],e=1,cnt;
long long pound(int l,int r){
	long long qqqq=0;
	for(int i=l;i<=r;i++)qqqq^=a[i];
	return qqqq;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=1;i<=n;i++){
	for(long long j=e;j<=i;j++){
		if(pound(j,i)==m){
	cnt++;
	e=i+1;
	break;
	}}
}
cout<<cnt;
	return 0;
}
