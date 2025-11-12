#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500];
int ming;
int sum=1;
int c,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) ming=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		int x=a[i];
		if(x!=ming) sum++;
		else break;
	}
	if(sum%n==0){
		c=sum/n;
		if(c%2==0) r=1;
		else r=n;
	}
	else{
		c=sum/n+1;
		if(c%2==0) r=n+1-sum%n;
		else r=sum%n;
	}
	cout<<c<<' '<<r;
	return 0;
} 