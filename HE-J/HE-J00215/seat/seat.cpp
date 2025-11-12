#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=107;
long long c[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,i,x,t,a,b;
	cin>>n>>m;
	for(i=0;i<n*m;i++){
		cin>>c[i];
	}
	x=c[0];
	sort(c,c+n*m);
	t=lower_bound(c,c+n*m,x)-c;
	t=n*m-t-1;
	a=t/n;
	b=t%n;
	if(a%2==1){
		b=n-b-1;
	}
	cout<<a+1<<' '<<b+1<<endl;
	return 0;
}
