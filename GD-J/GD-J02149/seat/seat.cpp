#include<bits/stdc++.h>
using namespace std;
int a[105];
bool d(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,q;
	cin>>n>>m>>q;
	a[1]=q;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,d);
	int s,c=0,r=0;
	for(int i=2;i<=n*m;i++){
		if(q==a[i])s=i;
	}
	c+=s/2/n;
	s%=(2*n);
	c++;
	if(s==0){c--;r=1;}
	else if(s>n){c++;r=2*n-s+1;}
	else r=s;
	cout<<c<<' '<<r;
	return 0; 
} 
