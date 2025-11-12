#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,r;
int a[]={};

int main(){	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(int i=n*m;i<=n;i++){
		cin>>n>>m;
		cin>>a[i];
		break;
	}
	sort(a+n,a+n+1);
	
	c+=1;
	r+=1;
	
	
	
	cout<<c<<' '<<r<<endl;
	return 0;
} 
