#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
bool b;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) b=1;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*(max(max(a[1],a[2]),a[3]))) cout<<1;
		else cout<<0;
	}
	if(!b){
		int l,c=1,d=n;
		for(int i=1;i<=n-2;i++){
			l+=c;
			c*=d;
			d++;
		}
		cout<<l;
	}
	
	return 0;
}
