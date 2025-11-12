	#include<bits\stdc++.h>
	using namespace std;
	long long N=1e5+10;
	int main(){
	freopen("seat.in","c ",stdin);
	freopen("seat.out","r",stdout);
	int n,m,c=1,r=1;
	cin>>n>>m;
	int x=n*m;
	int a[x];
	for(int i=1;i<=x;i++){
		cin>>a[x];
}
	for(int i=2;i<=x-1;i++){
		if(a[1]<a[i]){
			c++;
			if(c==n){
				r++;
			}
			else if(c>n){
			c--;
			}
		}
	}
	cout<<c<<r<<endl;
	return 0;
	}
	
