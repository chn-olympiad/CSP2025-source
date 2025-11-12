#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,d=0,e=1,b=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		d=d+a[i];
		e=max(a[i],e);
	}
	if(d>(e*2)){
	b++;
	cout<<b;
	}
	else
	cout<<0;
	return 0;
}
