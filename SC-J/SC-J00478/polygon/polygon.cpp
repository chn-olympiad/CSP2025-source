#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[5];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	if(m<3){
		cout<<0;
	}else if(m==3){
		int x=max(a[1],a[2]);
		x=max(x,a[3]);
		if(a[1]+a[2]+a[3]>2*x){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
