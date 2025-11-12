#include<bits/stdc++.h>
using namespace std;
int n,a[5050],ans=0;
void f(int x){
	if(x==n+1){
		return ;
	}
	f2(n,x);
	f(x+1);
}
void f2(int y){
	if()
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f(3);
	cout<<998244353%ans<<endl;
	return 0;
}
