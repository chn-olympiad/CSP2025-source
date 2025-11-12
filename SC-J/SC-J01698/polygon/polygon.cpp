#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(a>=b&&a>=c){
			if(b+c>a) cout<<1;
			else cout<<0;
		}else if(b>=a&&b>=c){
			if(a+c>b) cout<<1;
			else cout<<0;
		}else if(a+b>c) cout<<1;
		else cout<<0;
	}
	if(n<3){
		cout<<0;
	}
	return 0;
}