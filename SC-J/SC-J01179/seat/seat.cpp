#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,b=1;
vector<int> a(150,0);
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=n*m;
	cin>>a[1];
	for(int i=2;i<=x;i++){
		cin>>a[i];
		if(a[1]<a[i]){
			b++;
		}
	}
	c=b/n;
	r=b%n;
	if(r!=0){
		c++;
		if(c%2==0){
			r=n+1-r;
		}
		else{
			r=0+r;
		}
	}else{
		if(c%2==0){
			r=1;
		}
		else{
			r=n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
} 