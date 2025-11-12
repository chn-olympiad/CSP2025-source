#include <bits/stdc++.h>
using namespace std;

int co(int a,int b){
	int x=1,y=1;
	for(int i=a;i>=a-b+1;i--){
		x*=i;
	}
	for(int i=b;i>=1;i--){
		y*=i;
	}
	return x/y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,s=0;
	cin>>n;
	for(int i=3;i<=n;i++){
		s+=co(n,i);
	}
	cout<<s%998244353;
	return 0;
}
