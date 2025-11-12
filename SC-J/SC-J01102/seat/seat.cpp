#include<bits/stdc++.h>
using namespace std;
long long n,m,a,o=1;
int main(){
	freopen(" number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>n>>m;
	cin>>a;
	for(long long i=2;i<=n*m;++i){
	    long long g;
		cin>>g;
		if(g>a) ++o;
	}
	long long d=o%n,e=o/n;
	if(d) e++;
	if(e&1){
		if(!d) d=n;
	}else{
		d=n+1-d;
		if(d==n+1) d=1;
	}
	cout<<e<<" "<<d;
	return 0;
}