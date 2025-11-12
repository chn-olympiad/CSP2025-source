#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","e",stdin);
	int n,m,q,w=1,c,r;
	cin>>n>>m;
	q=n*m;
	long long a[q+9];
	for(long long z=1;z<=q;z++){
		cin>>a[z];
	}
	for(long long z=1;z<=q;z++){
		if(a[1]<a[z]){
			w++;
		}
	}
	c=w/n+1;
	r=w%n;
	if(w%n==0){
		cout<<c-1<<" "<<n;
	}else if(c%2!=0){
		cout<<c<<" "<<r;
	}else{
		cout<<c<<" "<<n-r+1;
	}
	return 0;
}
