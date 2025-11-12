#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int id=a[1],num;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==id)num=i;
	}
	int i,j;
	if(num%n==0)j=num/n;
	else j=num/n+1;
	if(num%(2*n)<=n&&num%(2*n)>=1)i=num%(2*n);
	else if(num%(2*n)==0)i=1;
	else i=n+1-(num%(2*n)-n);
	cout<<j<<" "<<i;
	return 0;
}
