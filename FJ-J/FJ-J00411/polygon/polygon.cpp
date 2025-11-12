#include <bits/stdc++.h>
using namespace std;
int n,num;
int a[5050];
int noid(int x){
	int c=1;
	for(int i=1;i<=x;i++)c*=i;
	return c;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3])num=1;
		cout<<num;
	}
	else{
		int y=0;
		for(int i=2;i<=n-1;i++)y+=i;
	}
	return 0;
}