#include<bits/stdc++.h>
using namespace std;
int n,m,pai=1,c,r;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			pai++;
		}
	}
	
	c=(pai-1)/m+1;
	if(c%2==0){
		r=n-pai%m+1;
	}else{
		r=pai-(c-1)*m;
	}
	cout<<c<<" "<<r;
	return 0;
}
