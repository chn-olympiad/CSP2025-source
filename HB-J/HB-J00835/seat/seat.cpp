#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int a[N*N];

int n,m,c,r;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	int a1=0;
	for(int i=0;i<n*m;++i){
		cin>>a[i];
	}
	a1=a[0];
	int wei=0;
	sort(a,a+n*m,greater<int>() );
	for(int i=0;i<n*m;++i){
		if(a[i] == a1)wei=i+1;
	}
	r = (wei+n-1) % n +1;
	c = ceil(wei*1.0 / n) ;
	if(c % 2 == 0)r= n - r +1;
	cout<<c<<" "<<r;
	return 0;
}
