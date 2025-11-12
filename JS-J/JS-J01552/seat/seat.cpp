#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],l=1;
	cin>>n>>m;
	int s=n*m;
	cin>>a[1];
	for(int i=2;i<=s;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			l++;
		}
	}
	int c,r;
	if(l%m==0){
		c=l/m;
		if(c%2==0)
			r=1;
		else
			r=m;
	}
	else{
		c=l/m+1;
		if(c%2==0)
			r=m-l%m+1;
		else
			r=l%m;
	}
	cout<<c<<' '<<r<<endl;
	return 0;
}
