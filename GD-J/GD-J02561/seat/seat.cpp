#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	double n,m;
	cin>>n>>m;
	vector<double> A(n*m);
	for(double i=0;i<n*m;i++){
		cin>>A[i];
	}
	double tar=A[0];
	sort(A.begin(),A.end());
	double rank;
	for(double i=0;i<n*m;i++){
		if(A[i]==tar){
			rank=n*m-i;
		}
	}
	double r,c;
	c=ceil(double(rank/n));
	if(int(c)%2==1){
		r=int(rank)%int(n);
		if(r==0)r=n;
	}
	else{
		r=n-int(rank)%int(n);
		if(r==n)r=1;
		else r++;
	}
	cout<<c<<" "<<r;
	return 0;
}
