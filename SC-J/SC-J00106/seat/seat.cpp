#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b,id=1,c[50],o;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n==0||m==0){
		return 0;
	}
	cin>>a;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(b>a){
			id++;
		}
	}
	//cout<<id;
	for(int i=1;i<=n;i++){
		c[i]=i;
		o++;
	}
	for(int i=n;i>=1;i--){
		c[o+1]=i;
		o++;
	}
	cout<<(id+n-1)/n<<" ";
	if(id%(2*n)==0){
		cout<<c[2*n];
		return 0;
	}
	cout<<c[id%(2*n)];
	return 0;
}