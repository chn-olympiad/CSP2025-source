#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	int x=a[1],y=a[2],z=a[3],s=0;
	if(x+y>z){
		s++;
	}
	if(y+z>x){
		s++;
	}
	if(x+z>y){
		s++;
	}
	cout<<s;
	return 0;
}
