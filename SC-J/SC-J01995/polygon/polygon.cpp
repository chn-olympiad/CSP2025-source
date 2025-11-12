#include<bits/stdc++.h>
using namespace std;
int n;
int a[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);                 
	int n;
	cin>>n;
	if(n<=3){
		cin>>a[1]>>a[2]>>a[3];
		sort(a+1,a+4);
		if(a[3]*2<a[1]+a[2]+a[3]) cout<<1;
		else cout<<0;
	}
	int top=0;
	for(int i=3;i<=n;i++){
		top+=n-i+1;
	}
	cout<<top;
}