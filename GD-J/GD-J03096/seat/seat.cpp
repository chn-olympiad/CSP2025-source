#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	double n,m,a,b,s=1;
	cin>>n>>m>>a;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(b>a) s++;
	}
	long long h=ceil(s/n),l=(long long)s%(long long)m;
	if(l==0) l=m;
	cout<<h<<' '<<(h%2==0?(m+1)-l:l);
	return 0;
}
